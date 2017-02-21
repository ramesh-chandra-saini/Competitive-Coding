/*
    MAP Basic Function
    C++ STL
*/

#include<bits/stdc++.h>
using namespace std;
void printMap(map<string,long>&myMap){
    printf("--------------MAP-----------------------\n");
    for(map<string,long>::iterator it=myMap.begin();it!=myMap.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    printf("--------------MAP-----------------------\n");
}
int main(){

    map<string,long> myMap;

    //insertion
    myMap["Ramesh"] = 8546896750;
    myMap.insert(make_pair("Sunil",8546896750));

    printMap(myMap);

    //find with key
    map<string,long> ::iterator it;
    it=myMap.find("Sunil");
    if(it!=myMap.end()){
        cout<<"Found --> ";
        cout<<it->first<<" "<<it->second<<endl;
    }else
        cout<<"Not Found"<<endl;

    it=myMap.find("anil");
    if(it!=myMap.end()){
        cout<<"Found --> ";
        cout<<it->first<<" "<<it->second<<endl;
    }else
        cout<<"Not Found"<<endl;


    //delete
    printMap(myMap);
    //when key is present map
    myMap.erase("Sunil");
    printMap(myMap);

    //when key is not present
    myMap.erase("anil");
    printMap(myMap);
}
