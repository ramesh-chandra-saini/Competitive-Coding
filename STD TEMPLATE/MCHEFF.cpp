/*

    RAMESH CHANDRA 22 SEP 2015

    DYNAMIC PROGRAMMING
    INTEGER KNAPSACK
    SORTING OF INTERVALS
    GOOD HASHING

    O() -- WILL SEE
*/

/*

Constraints

1 ≤ T ≤ 10^5
1 ≤ N,M ≤ 10^5
1 ≤ K ≤ 500
1 ≤ Li ≤ Ri ≤ N
1 ≤ Ci ≤ 200
-10^9 ≤ Ai ≤ 10^9
Sum of N and M over all test cases does not exceed 5*10^5
*/

#include<bits/stdc++.h>
using namespace std;

bool _cmp(const pair<int , pair< int ,int > > &A , const pair< int, pair < int, int  > > &B){

    if(A.first!=B.first) return A.first < B.first;
    if(A.second.first!=B.second.first) return A.second.first < B.second.first;
    return A.second.second < B.second.second;
}

int main(){

    int T;
    cin >> T;

    while(T--){

        int N,K,M;

        cin >> N >> K >> M;

        int rating[N];

        for(int i=0;i<N;++i){

            cin >> rating[i];
        }

        ///pair< cost,pair< st_idx,ind_idx> > values;
        vector< pair< int,pair< int,int > > > _cost; _cost.clear();

        int cost,st_idx,end_idx,value;

        for(int i=0;i<M;i++){

            cin >> st_idx  >> end_idx >> cost;

                if(cost<=K)
                _cost.push_back(make_pair( cost, make_pair(st_idx,end_idx)));
        }

        int size=_cost.size();

        //just print cost vector which can be useful in future..
        //for(int i=0;i<size;i++){cout<<_cost[i].first<<" "<<_cost[i].second.first<<" "<<_cost[i].second.second<<endl;}

       //sort based on cose
        sort(_cost.begin(),_cost.end(),_cmp);
        //for(int i=0;i<size;i++){cout<<_cost[i].first<<" "<<_cost[i].second.first<<" "<<_cost[i].second.second<<endl;}
        //this will hold final mininmum cost for knapsack
        vector<int> min_cost_holder(N,INT_MAX);

        //now time to store filled interval

        //just put values to cost holder which is minimum only one segment\

        value=_cost[0].first;st_idx=_cost[0].second.first;end_idx=_cost[0].second.second;

        for(int i=st_idx;i<= end_idx;++i){

             min_cost_holder[i]=value;
        }

        //vector< pair< st_idx,end_idx > > interval_info;
        vector< pair< int ,int > > interval_info; interval_info.clear();
        //now tym to put all interval vales ....let see

        interval_info.push_back(make_pair(st_idx,end_idx));

         for(int i=0;i<interval_info.size();++i) cout<< interval_info[i].first<<" "<<interval_info[i].second<<endl;

        int min_st_idx;
        int max_end_idx;
        for(int i=1;i<size;++i){


            value = _cost[i].first;
            min_st_idx  =  st_idx = _cost[i].second.first;
            max_end_idx = end_idx = _cost[i].second.second;

            int overlap=INT_MIN;

            for(int j=st_idx;j<=end_idx;++j){


                    if(min_cost_holder[j]==INT_MAX){

                            min_cost_holder[j]=value;
                    }
                    else{

                         int idx=interval_info.size();


                         bin_search(interval_info,0,interval_info.size()-1,j,idx);
                         overlap=min(overlap,interval_info[idx].first);

                         j=interval_info[idx].second;
                         min_st_idx=min(min_st_idx,interval_info[idx].first);
                         max_end_idx=max(max_end_idx,interval_info[idx].second);
                         interval_info.erase(interval_info.begin()+idx);
                    }
            }
            if(overlap==INT_MAX){

                interval_info.push_back(make_pair(min_st_idx,max_end_idx));
            }
            else{

                    /*int idx=interval_info.size();
                    bin_search(interval_info,0,interval_info.size()-1,max_end_idx+1);

                    if(idx!=interval_info.size())
                    {
                        overlap=min(overlap,interval_info[idx].first);
                        min_st_idx=min(min_st_idx,interval_info[idx].first);
                        max_end_idx=max(max_end_idx,interval_info[idx].second);
                        interval_info.erase(interval_info.begin()+idx);

                    }*/

                    interval_info.insert(interval_info.begin()+overlap,make_pair(min_st_idx,max_end_idx));
            }

            for(int __i=0;__i<interval_info.size();++__i) cout<< interval_info[__i].first<<" "<<interval_info[__i].second<<endl;
            for(int _i=0;_i<N;_i++) cout<<min_cost_holder[_i]<<" "; cout<<endl;
    }
    for(int i=0;i<N;i++) cout<<min_cost_holder[i]<<" "; cout<<endl;
    }
    return 0;
}
