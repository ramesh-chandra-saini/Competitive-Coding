/*
    maximum AND of two element of given array
*/
/*
/*
    RAMESH CHANDRA 17 SEP 2015
    PROBLEM : https://www.codechef.com/problems/TAAND
    DATA STRUCTURE : TRIE
    BITWISE PROGRAMMING
    TIME COMPLEXITY : O(Nlog Amax)
*/

#include<bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)

//structure of Trie
typedef struct Trie{

    struct Trie * zero;
    struct Trie * one;
} trie;

//create a New node
trie* getNode(){

    trie* _new=(trie*)malloc(sizeof(trie));
    _new->zero=_new->one=NULL;
    return _new;
}

//insert new value into Trie

void _insert(trie * it,int value,int bits){

    int bitwise[bits];

    //convert decimal into binary
    //cout<<value<<"(";
    for(int i=bits-1;i>=0;i--,value=(value>>1))
        bitwise[i]=value&1;
    //cout<<"";for(int i=0;i<bits;i++) //cout<<bitwise[i]; //cout<<")"<<endl;
    for(int i=0;i<bits;i++){

        if(bitwise[i]){

            if(!it->one)
                it->one=getNode();
            it=it->one;
        }
        else{

            if(!it->zero)
                it->zero=getNode();
            it=it->zero;
        }
    }
}

//calculate AND
int _cal_AND(trie * it,int value,int bits){

    int bitwise[bits];

    //convert decimal into binary
    //cout<<value<<"(";
    for(int i=bits-1;i>=0;i--,value=(value>>1))
        bitwise[i]=value&1;
    //cout<<"";for(int i=0;i<bits;i++) //cout<<bitwise[i]; //cout<<")"<<endl;
    int ans=0;

    for(int i=0;i<bits;i++){

        ans=(ans<<1);
        if(bitwise[i]){

            if(it->one){

                ans++;
                it=it->one;
            }
            else
                it=it->zero;
        }
        else{

            if(it->zero){

                it=it->zero;
            }
            else
               it=it->one;
        }
    }
    //cout<<"ANS : "<<ans<<endl;
    return ans;
}
int main(){


   cout<<pow(2,64)<<endl;
    int N;

    read(N);

    int arr[N];
    int _max=INT_MIN;
    for(int i=0;i<N;i++){
        read( arr[i]);
        _max=max(_max,arr[i]);
    }
    int bits=0;
    do{

        ++bits;
        _max=(_max>>1);
    } while(_max);

     //create Trie
     trie * _trie=getNode();

     //insert first element
     _insert(_trie,arr[0],bits);

     int ans=0; //final ans to judge

     for(int i=1;i<N;i++){

        ans=max(ans,_cal_AND(_trie,arr[i],bits));
        _insert(_trie,arr[i],bits);
     }
    write(ans);
/*
       // CHECKER FUNCTION : NAIVE APPROACH

        ans= INT_MIN;

        for(int i=0;i<N-1;i++){

            for(int j=i+1;j<N;j++){

                ans=max(ans, (arr[i]&
                arr[j]));
            }
        }
        cout<<ans<<endl;*/

    return 0;
}
