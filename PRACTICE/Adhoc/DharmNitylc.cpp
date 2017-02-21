#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define scan(x) scanf("%lld",&x)
int main()
{
int  k,N,i,j,num;
int ans=0;
scan(k);
vector< set<int> >val(k);
    for(i=0;i<k;i++)
    {
       scan(N);
        for(j=0;j<N;j++)
        {
                scan(num);
                val.at(i).insert(num);
            }

        }

        set< pair<int,int> > heap;
        heap.clear();
        int  key;
        for(i=0;i<k;i++)
            {

            num=*(val.at(i).begin());val.at(i).erase(val.at(i).begin());
            heap.insert(make_pair(num,i));
            }
         ans=(*(heap.rbegin())).first-(*(heap.begin())).first;
         bool cond=true;
          while(cond)
          {
               num=(*(heap.begin())).second;
               heap.erase((heap.begin()));
               if(val.at(num).empty()==true) cond=false;
               else
               {
                  key=*(val.at(num).begin());val.at(num).erase(val.at(num).begin());
                  heap.insert(make_pair(key,num));
                  ans=min(ans,(*(heap.rbegin())).first-(*(heap.begin())).first);
               }

          }
        printf("%d\n",ans);
        return(0);
}
