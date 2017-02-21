
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<double> suchandSol(long long hypo,long long area){
    vector<double> ans;
    double pro=area*2;
    double sum=sqrt((hypo*hypo)+2*pro);
    double determinant = sum*sum - 4*1*pro;
//printf("%lf %lf is sum,determinant\n",sum,determinant);
    if(determinant<0) ans.push_back(-1);
    else{
        double x1 = (sum + sqrt(determinant)) / (2*1);
        double x2=sum-x1;
        ans.push_back(x2);ans.push_back(x1);ans.push_back((double)hypo);
    }
    return ans;
}
vector<double> dharmendraSol(long long h,long long s){
    vector<double> ANS;
   double s1,s2;
   s1=h*h+4*s;
   s2=h*h-4*s;
   if(s2<0) ANS.push_back(-1);
   else{
       s1=sqrt(s1);
       s2=sqrt(s2);
       double a,b,c;
       a=(s1+s2)/(2.0);
       b=(s1-s2)/(2.0);
       c=sqrt(a*a+b*b);
       vector<double>res;
       res.push_back(a);res.push_back(b); res.push_back(c);
       sort(res.begin(),res.end());
       ANS=res;
   }
   return ANS;
}
int main(){
    int t; cin >> t;
    string flag("AC");int T=t;
    while(t--){
        long long int H,S;
        H=1+rand()%1000000;
        S=1+rand()%1000000000000;
        vector<double> suchandAns=suchandSol(H,S);
        vector<double> dharmendraAns=suchandSol(H,S);
        flag=(suchandAns==dharmendraAns)?flag:"WA";
        /*if(suchandAns==dharmendraAns ) cout<<"VERDICT : AC"<<endl;
        else cout<<"VERDICT : WA"<<endl;
        cout<<"Suchand Solution ";for(int i=0;i<suchandAns.size();i++) cout<<suchandAns[i]<<" "; cout<<endl;
        cout<<"Dharmendra Solution ";for(int i=0;i<dharmendraAns.size();i++) cout<<dharmendraAns[i]<<" "; cout<<endl; cout<<endl;*/
    }
    cout<<"TestCases : "<<T<<endl;
    cout<<"FINAL VERDICT : "<<flag<<endl;
}
