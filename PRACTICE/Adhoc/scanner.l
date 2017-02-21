Digit			[0-9]            
Alpha			[a-zA-Z_]
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
int i,var_cnt=0,comment=0,bracCount=0;
char typ[3];
struct holder
{
	char name[33];
	char type[33];
}st[20];

   
%}
      
comment (\/\/.*)
comstart (\/\*)
comend (\*\/)
keyword "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"	

relop >|<|<=|>=|!=
whitespace [ \t]+

%%

^#([-a-zA-Z0-9.]|{relop}|{whitespace})* {fprintf(yyout,"\n%s\t\t\tPreprocessor Statement\t\t\t\t",yytext);}

{comment}           {if(comment<=0) fprintf(yyout,"\n//\t\t\t\t\tLine Comment\t\t\t\t\t\t");};
{comstart}            {comment++; 
                       if(comment>1) 
                         fprintf(yyout,"\n\tERROR: Nested Comment");
                       else
                         fprintf(yyout,"\n/*\t\t\t\t\tML Comment Sarts\t\t\t\t\t\t");
                    }
{comend}            {   if(comment>0)
                        {
                          comment--;
                          fprintf(yyout,"\n*/\t\t\t\t\tML Comment Ends\t\t\t\t\t\t");
                        }
                        else
                            fprintf(yyout,"\n\tERROR: */ found before /* ");
                    }
{keyword}                   {
                              if(comment<=0){
                                 fprintf(yyout,"\n%s\t\t\t\t\tKeyword\t\t\t\t\t\t",yytext);
                                 strcpy(typ,yytext);
                              }
                              
                            }

{Alpha}+\(                  {
                              if(comment<=0)
                              {
                                for(i=0;i<var_cnt;i++)
     			           if(strcmp(st[i].name,yytext)==0)
      	                             break;   

    		         	   if(i==var_cnt)  
     	                           {
                                     strcpy(st[var_cnt].name,yytext);
                                     strcpy(st[var_cnt++].type,"FUNCTION");
                                   }
             	                 fprintf(yyout,"\n%s\t\t\t\t\tFunction\t\t\t\t\t",yytext);

                              }
                             }


{Alpha}({Alpha}|{Digit})*   {
                              if(comment<=0)
                              {
                                for(i=0;i<var_cnt;i++)
     			           if(strcmp(st[i].name,yytext)==0)
      	                             break;   

    		         	   if(i==var_cnt)  
     	                           {
                                     strcpy(st[var_cnt].name,yytext);
                                     strcpy(st[var_cnt++].type,typ);
                                   }
             	                 fprintf(yyout,"\n%s\t\t\t\t\tIdentifier\t\t\t\t\t",yytext);

                              }
                             }


{Digit}+                    {
                              if(comment<=0)
                              {
                                for(i=0;i<var_cnt;i++)
     			           if(strcmp(st[i].name,yytext)==0)
      	                             break;   

    		         	   if(i==var_cnt)  
     	                           {
                                     strcpy(st[var_cnt].name,yytext);
                                     strcpy(st[var_cnt++].type,"int");
                                   }
             	                 fprintf(yyout,"\n%s\t\t\t\t\tInt Constant\t\t\t\t\t",yytext);

                              }
                             }
{Digit}+\.{Digit}+          {
                              if(comment<=0)
                              {
                                for(i=0;i<var_cnt;i++)
     			           if(strcmp(st[i].name,yytext)==0)
      	                             break;   

    		         	   if(i==var_cnt)  
     	                           {
                                     strcpy(st[var_cnt].name,yytext);
                                     strcpy(st[var_cnt++].type,"float");
                                   }
             	                 fprintf(yyout,"\n%s\t\t\t\t\tInt Constant\t\t\t\t\t",yytext);

                              }
                             }

\"(\\.|[^\\"])*\"   {if(comment<=0) fprintf(yyout,"\n%-39s String Literal\t\t\t\t\t",yytext);}
\"(\\.|[^\\"])*	    {if(comment<=0) printf("ERROR: String does not end\n");}

"{" 		            {if(comment<=0) {fprintf(yyout,"\n%s\t\t\t\t\tPunctuator\t\t\t\t\t",yytext);bracCount++;}}
"}" 	   	            {if(comment<=0) {fprintf(yyout,"\n%s\t\t\t\t\tPunctuator\t\t\t\t\t",yytext);bracCount--;}}

","|";"|":"|"("|")"|"."	    {if(comment<=0) fprintf(yyout,"\n%s\t\t\t\t\tPunctuator\t\t\t\t\t",yytext);}
"&"|"!"|"~"|"+"|"-"|"*"|"/"|"%"|"<"|">"|"^"|"|"|"?"|"="|{relop}|"..."|">>="|"<<="|"+="|"-="|"*="|"/="|"%="|"&="|"^="|"|="|">>"|"<<"|"++"|"--"|"->"|"&&"|"||"|"<=" {if(comment<=0) fprintf(yyout,"\n%s\t\t\t\t\tOperator\t\t\t\t\t",yytext);}

[ \t\v\n]		{;}
%%

int main(int argc,char **argv)
{
printf("%s\n",argv[1]);
 if(argv[1]==NULL)
  printf("Error opening file\n");
 else
 {
   yyin=fopen(argv[1],"r");
  
   printf("\n\n\nTable Format is:\n Lexeme\t\t\t\t\tToken\n");
   yylex();
   if(comment!=0)
     printf("\n\tERROR: Comment does not end\n");
   if(bracCount!=0)
     printf("\n\tERROR: Bracket mismatch\n");
   printf("\n");
   
   printf("\n\n\n\t\t\t   Sybol-Constants table\n");
   printf("\n\t\t\t    Symbol\tType\n");
   printf("---------------------------------------------------------------------------------------\n"); 
   for(i=0;i<var_cnt;i++)
   {

     printf("%33s",st[i].name);
     printf("\t%s\n\n",st[i].type);
   }

   printf("---------------------------------------------------------------------------------------\n");
 }
}
int yywrap()
{
 return(1);
}
