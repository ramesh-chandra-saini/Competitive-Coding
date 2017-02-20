#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int headx=1,heady=1,tailx=1,taily=1;
string str;
 #include<string.h>
#include<stdlib.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
typedef long long int INT;
inline void read(int &x){
	scanf("%d",&x);
	/*register int c = gc();	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc())
	{	x = (x<<1) + (x<<3) + c - 48; }
	*/
}
inline void write(int a){
    printf("%d ",a);
/*
    char snum[35];int i = 0;
    do{
        snum[i++] = a%10 +48;
        a = a/10;
    }while(a!= 0);
    --i; while(i>=0)pc(snum[i--]); pc(' ');
    */
}
inline void readStr(){
    cin >> str;
/*
	register char c = gc(); str.clear();
	for(;(c<'A' || c>'Z');c = gc());
	for(;c>='A' && c<='Z';c = gc())
	{	str=str+c; }*/
}
inline void writeStr(char A[]){
    printf("%s ",A);
    /*int L=strlen(A);
    for(int i=0;i<L;i++) pc(A[i]); pc(' ');*/
}
void fun(int x,int y){
        writeStr("MOVE"); write(headx);write(heady); write(x); write(y);pc('\n');
        //cout<<"MOVE "<<headx<<" "<<heady<<" "<<headx<<" "<<(heady-1)<<endl;
        headx=x; heady=y; arr[headx][heady]=true;
}
int main(){

    int n,m,k;  read(n); read(m); read(k);// cin >> n >> m >> k;
    bool arr[n+2][m+2];
    for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) arr[i][j]=false;
    for(int i=0;i<=m+1;i++) arr[0][i]=arr[n+1][i]=true; //Blocked Cells
    for(int i=0;i<=n+1;i++) arr[i][0]=arr[i][m+1]=true; //Blocked Cells
    //for(int i=0;i<=n+1;i++){for(int j=0;j<=m+1;j++){cout<<arr[i][j]<<" ";} cout<<endl;} cout<<endl;
    for(int i=0,x,y;i<k;i++){
         read(x); read(y);//       cin >> x >> y;
        arr[x][y]=true; //Blocked Cells
    }
    bool step=true;
    bool snakeLive=false;

    bool myTurn=true;
    while(step){
        if(myTurn==true){
            if(snakeLive == false){//snake is dead or not born
                bool findEmptyCell=false;int X,Y;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(arr[i][j]==false){
                            findEmptyCell = true; X=i;Y=j; break; }}}
                if(findEmptyCell==false) {
                   writeStr("EXIT");pc('\n'); // cout<<"EXIT"<<endl;
                    snakeLive=false; step=false;
                }
                 else{
                 writeStr("NEW");write(X);write(Y); pc('\n');
                 //cout<<"NEW"<<X<<" "<<Y<<endl;
                 arr[X][Y]=true;
                    headx=tailx=X; heady=taily=Y; snakeLive=true;
                }
            } else{//snake is live..
                //move
                if(arr[headx][heady-1] == false){fun(headx,heady-1);} //(headx,heady-1)
                else if(arr[headx][heady+1] == false){ fun(headx,heady+1);}// cout<<"MOVE "<<headx<<" "<<heady<<" "<<headx<<" "<<(heady+1)<<endl; arr[headx][heady+1] =true;
                    //headx=headx; heady=heady+1;arr[headx][heady]=true; } //(headx,heady-1)
                else if(arr[headx-1][heady] == false){ fun(headx-1,heady);}//cout<<"MOVE "<<headx<<" "<<heady<<" "<<(headx-1)<<" "<<(heady)<<endl; arr[headx-1][heady] =true;
                    //headx=headx-1; heady=heady;arr[headx][heady]=true; } //(headx,heady-1)
                else if(arr[headx+1][heady]==false){ fun(headx+1,heady);}
               //cout<<"MOVE "<<tailx<<" "<<taily<<" "<<(tailx+1)<<" "<<(taily)<<endl; arr[tailx+1][taily] =true;
                    //tailx=tailx+1; taily=taily;arr[tailx][taily]=true;} //(tailx,taily-1)
                else if(arr[tailx][taily-1] == false){fun(tailx,taily-1);} //(tailx,taily-1)
                else if(arr[tailx][taily+1] == false){ fun(tailx,taily+1);}// cout<<"MOVE "<<tailx<<" "<<taily<<" "<<tailx<<" "<<(taily+1)<<endl; arr[tailx][taily+1] =true;
                    //tailx=tailx; taily=taily+1;arr[tailx][taily]=true; } //(tailx,taily-1)
                else if(arr[tailx-1][taily] == false){ fun(tailx-1,taily);}//cout<<"MOVE "<<tailx<<" "<<taily<<" "<<(tailx-1)<<" "<<(taily)<<endl; arr[tailx-1][taily] =true;
                    //tailx=tailx-1; taily=taily;arr[tailx][taily]=true; } //(tailx,taily-1)
                else if(arr[tailx+1][taily] == false){ fun(tailx+1,taily);}//cout<<"MOVE "<<tailx<<" "<<taily<<" "<<(tailx+1)<<" "<<(taily)<<endl; arr[tailx+1][taily] =true;
                    //tailx=tailx+1; taily=taily;arr[tailx][taily]=true;} //(tailx,taily-1)

                /*else if(arr[tailx][taily-1] == false){ cout<<"MOVE "<<tailx<<" "<<taily<<" "<<(tailx)<<" "<<(taily-1)<<endl; arr[tailx][taily-1] =true;
                    tailx=tailx;taily=taily-1; arr[tailx][taily]=true;} //(headx,heady-1)
                else if(arr[tailx][taily+1] == false){ cout<<"MOVE "<<tailx<<" "<<taily<<" "<<(tailx)<<" "<<(taily+1)<<endl; arr[tailx][taily+1] =true;
                    tailx=tailx; taily=taily+1;arr[tailx][taily]=true;} //(headx,heady-1)
                else if(arr[tailx-1][taily] == false){ cout<<"MOVE "<<tailx<<" "<<taily<<" "<<(tailx-1)<<" "<<(taily)<<endl; arr[tailx-1][taily] =true;
                    tailx=tailx-1; taily=taily;arr[tailx][taily]=true;} //(headx,heady-1)
                else if(arr[tailx+1][taily] == false){ cout<<"MOVE "<<tailx<<" "<<taily<<" "<<(tailx+1)<<" "<<(taily)<<endl; arr[tailx+1][taily] =true;
                    tailx=tailx+1; taily=taily;arr[tailx][taily]=true;} //(headx,heady-1)
                */else{
                    bool findEmptyCell=false;int X,Y;
                    for(int i=1;i<=n;i++){
                        for(int j=1;j<=m;j++){
                            if(arr[i][j]==false){
                                findEmptyCell = true; X=i;Y=j;break;}}}
                    if(findEmptyCell==false) {
                       writeStr("EXIT"); pc('\n');//    cout<<"EXIT"<<endl;
                        step=false;
                    }
                    else{
                     writeStr("NEW"); write(X); write(Y); pc('\n'); // cout<<"NEW "<<X<<" "<<Y<<endl;
                    headx=tailx=X; heady=taily=Y; snakeLive=true; arr[X][Y]=true;}
                }
            }
        }else{
             str.clear(); readStr();// cin >> str;
             int a,b,c,d;
            if(str == "EXIT"){ step=false;snakeLive=false;//terminate program
            }else if(str == "FREEZE"){ read(a); //cin>>a;//don't do anything
            }else if(str=="NEW"){  read(a); read(b);// cin>>a>>b;
            arr[a][b]=true;//fill this cell
            } else { read(a);read(b);read(c);read(d);// cin>>a>>b>>c>>d;
             arr[a][b]=true;arr[c][d]=true;
            }
        }
        myTurn = (true^myTurn);
    }
    return 0;
}
