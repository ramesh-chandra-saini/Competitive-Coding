#include<bits/stdc++.h>
using namespace std;
int main(){
    int  n; scanf("%d",&n);
    vector<int>a(n);for(int i=0;i<n;i++)scanf("%d",&a[i]);
    vector<int>b(a);sort(b.begin(),b.end());
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[j]==b[i]){
                while(j>i){
                    printf("%d %d\n",j,j+1);
                    swap(a[j-1],a[j]),j--;//perform swap whichever you printed to perform
                }    break;
            }
    return 0;
}
