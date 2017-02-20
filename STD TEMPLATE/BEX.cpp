/*
https://www.codechef.com/problems/BEX
*/
/*

    RAMESH CHANDRA 19 SEP 2015
    MOST HORRIBLE STL USED SO FAR
    PAIR, VECTOR,SET,STRING,MEP
*/

#include<bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)

int main(){

    int N,M,min_exe,Time;
    cin >> N;

    string book,book2;
    //horrible map........:(
    // map<key,pair< freq,vector< pair< Time,book> > > > _map
    map < int, pair<int,vector< pair<int,string >  > > > _map;
    set<int> _set;

    //just wash hand before use
    _map.clear(); _set.clear();

    for(int i=0;i<N;i++) {

        cin >>M;

        //just put book into pile
        if(M!=-1){

            cin>>book;
           _set.insert(M);
           _map[M]=make_pair( _map[M].first+1, make_pair(i,book) ) );
        }
        else{


        //remove book from pile having minimum number of exercise

            min_exe=*(_set.begin()); //minimum number of exercise
            int freq=(_map[min_exe]).first;
            int size=(_map[min_exe].second).size();
            pair<int,string> entry=(_map[min_exe].second).at(size-1);
            Time=entry.first;
            book2=entry.second;

            cout<<(Time-2)<<" "<<book2<<endl;

            if(freq==1){

                _set.erase(min_exe);
                _map.erase(_map[min_exe]);
            }
            else{
               _map[min_exe].second.erase(_map[min_exe].second.begin()+size-1,_map[min_exe].second.end());
               _map[min_exe].first--;
            }
        }
    }
    return 0;
}
