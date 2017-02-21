/*
*   RAMESH CHANDRA  , 23 MARCH 2016
*   NATIONAL INSTITUTE OF TECHNOLOGY KARNATAKA SURATHKAL
*/
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n; cin>>n;
    int ans=n,x,y,size=0,d;
    bool Excluded[n];  memset(Excluded,false,sizeof(Excluded));
    vector<pair<int,int> > Pairvec;Pairvec.clear();
    vector< pair<int, pair<int,int> > > vec(n);
    for(int i=0;i<n;i++){
        cin >> x >> y; vec[i]=make_pair(y-x+1,make_pair( x,y ));
    }

    for(int i=0;i<n;i++){//simple covered interval excluded//no use of x-y
        x=vec[i].second.first; y=vec[i].second.second;//check for this interval
        for(int j=0;j<n;j++){
            if(i!=j && x>=vec[j].second.first && y<=vec[j].second.second && Excluded[j] == false){
               Excluded[i]=true; break;
            }
        }
    }
    for(int i=0;i<n;i++){//take only which are not excluded yet
        if(Excluded[i] == false ) Pairvec.push_back(vec[i].second);
    }
    sort(Pairvec.begin(),Pairvec.end());
    bool Merged[n];  memset(Merged,false,sizeof(Merged));
    vector< vector<pair<int,int> >  > Svec; Svec.clear();
    bool lastMerged=false; int idx=0;
    int Psize[n];
    for(int i=0;i<Pairvec.size();){//now real merging started and marker for merged interval also mentioned..why?D:
        bool flag=true;pair<int,int> I=Pairvec[i];
        for(int j=0;j<Pairvec.size();j++){
            if( i!=j && Pairvec[i].second +1 >= Pairvec[j].first && Pairvec[i].second  <= Pairvec[j].second){
                    Pairvec[i].first = min(Pairvec[i].first,Pairvec[j].first);
                    Pairvec[i].second = max(Pairvec[i].second,Pairvec[j].second);
                    Pairvec.erase(Pairvec.begin()+j);
                    Merged[i]=Merged[j]=true;flag=false;

                }else if(i!= j && Pairvec[i].first <= Pairvec[j].second +1 && Pairvec[i].first >= Pairvec[j].first){
                    Pairvec[i].first = min(Pairvec[i].first,Pairvec[j].first);
                    Pairvec[i].second = max(Pairvec[i].second,Pairvec[j].second);
                    Pairvec.erase(Pairvec.begin()+j);
                    Merged[i]=Merged[j]=true;flag=false;
                }
                if(flag == false){
                    if(lastMerged){
                        Svec[idx-1][0]=Pairvec[i];
                        Svec[idx-1].push_back(I);
                    }else{
                        vector<pair<int,int> > k;k.clear();k.push_back(Pairvec[i]);
                        Svec.push_back(k);
                        Svec[idx].push_back(make_pair(Pairvec[i],I));
                        Psize[idx]=Svec[idx].size();
                        idx++;
                    }
                    lastMerged=true;
                    break;
                }else lastMerged=false;
            }
            i+=flag;
    }
/*
    for(int i=0;i<n;i++){//exclude after merging
        //x=vec[i].second.first; y=vec[i].second.second;//check for this interval
        for(int j=0;j<idx && Excluded[i] == false;j++){
            if(i!=j && x>=Svec[j][0].first && y<=Svec[j][0].second ){
                bool decide=true;
                for(int k=0;k<Psize[j];k++){
                    pair<int,int> a,b;//a=Svec[j][k];b=vec[i].second;
                    if( a== b) {decide=false;break;}
                }
               if(decide){Excluded[i]=true; break;}
            }
        }
    }
*/
    for(int i=0;i<n;i++)//calculate final ans..merged interval never exclude...satya vachan:P
        ans-=Excluded[i];
    cout<<ans<<endl;
    return 0;
}
