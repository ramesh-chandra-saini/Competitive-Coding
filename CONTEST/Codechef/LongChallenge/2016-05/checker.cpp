#include<bits/stdc++.h>
using namespace std;
int compareVersion(string A, string B) {
    int a=0;for(int i=0;i<A.length();i++) if(A[i]=='.') a++;//counting number of dots in A
    int b=0;for(int i=0;i<B.length();i++)if(B[i]=='.') b++;//counting number of dots in B
    if(a>=b) for(int i=1;i<=a-b;i++) B+=".0";//adding extra dots into B
    else for(int i=1;i<=b-a;i++) A+=".0";//adding extra dots into A
    //cout<<A<<"  "<<B<<endl;
    bool flagDot=false;string _A,_B; _A.clear();_B.clear();//not make two more dummies string to store non leading zero string in each dotted segment
    for(int i=0;i<A.length();i++){
        if(A[i]=='.'){flagDot=false;_A.push_back('.');}//take dot as it is..
        else if(A[i]=='0'){//check zero whether leading or significant..
            if(flagDot==true) _A.push_back(A[i]);//significant zeros as number greater than zero has already taken place..
            else ;//just skip..assume as leading zero..
        }else if(A[i]>'0'){flagDot=true;_A.push_back(A[i]);}//add significant numbers
    } flagDot=false;
    for(int i=0;i<B.length();i++){
        if(B[i]=='.') flagDot=false,_B.push_back('.');
        else if(B[i]=='0'){
            if(flagDot==true)_B.push_back(B[i]);//significant zeros
            else ;//just skip..assume as leading zero
        }else{
            flagDot=true;
            _B.push_back(B[i]);
        }
    }
    //now make each segment equal length
    //cout<<_A<<"  "<<_B<<endl;
    vector<int> Adigit,Bdigit; Adigit.clear();Bdigit.clear();
    a=0;for(int i=0;i<_A.length();i++){
        if(_A[i]=='.') Adigit.push_back(a),a=0;
        else a++;
    } Adigit.push_back(a),a=0;
    for(int i=0;i<_B.length();i++){
        if(_B[i]=='.') Bdigit.push_back(a),a=0;
        else a++;
    } Bdigit.push_back(a),a=0;
    //for(int i=0;i<Adigit.size();i++) cout<<Adigit[i]<<"\t"; cout<<endl;
    //for(int i=0;i<Bdigit.size();i++) cout<<Bdigit[i]<<"\t"; cout<<endl;
    int pos=0;for(int i=0;i<Adigit.size();i++){
        string extra; extra.clear();
        if(Adigit[i]<Bdigit[i]){
            for(int zero=1;zero<=Bdigit[i]-Adigit[i];zero++)
                extra.push_back('0');
            _A.insert(pos,extra);
        }else if(Adigit[i]>Bdigit[i]){
            for(int zero=1;zero<=Adigit[i]-Bdigit[i];zero++)
                extra.push_back('0');
            _B.insert(pos,extra);
        }
        //cout<<"PUSH : "<<extra<<endl;
        pos+=max(Adigit[i],Bdigit[i])+1;
    }
     //cout<<_A<<"  "<<_B<<endl;
    return (_A>_B)?1:(_A==_B)?0:-1;
}
int main(){
/*
 std::string str="to be question";
  std::string str2="the ";
  std::string str3="or not to be";
  std::string::iterator it;

  // used in the same order as described above:
  str.insert(6,str2);   cout<<str<<endl;              // to be (the )question
  str.insert(6,str3,3,4);             // to be (not )the question
  str.insert(10,"that is cool",8);    // to be not (that is )the question
  str.insert(10,"to be ");            // to be not (to be )that is the question
  str.insert(15,1,':');               // to be not to be(:) that is the question
  it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
  str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
  str.insert (it+2,str3.begin(),str3.begin()+3); // (or )

  std::cout << str << '\n';
  */

    //string A("1.2"),B("1.2.3.4.5");
    string A("4444371174137455"),B("5.168");
   cout<<compareVersion(A,B)<<endl;
}
