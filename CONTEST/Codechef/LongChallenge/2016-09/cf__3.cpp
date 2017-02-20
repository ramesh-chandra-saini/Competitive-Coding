#include<bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct Node{
    struct Node *zero;
    ll data;
    struct Node *one;
} node;

node *getNewNode(ll value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->zero=NULL;
    newNode->one=NULL;
}
node *root = getNewNode(0LL);

void insertValue(ll value){
    node *it;
    it=root;
    do{
        ll parity = value%2LL;
        value/=10LL;
        if(parity==0LL){
            if(it->zero==NULL){
                it->zero=getNewNode(0LL);
            }
            it=it->zero;
        }else{
            if(it->one==NULL){
                it->one=getNewNode(0LL);
            }
            it=it->one;
        }
    }while(value);
    it->data+=1LL;
    //cout<<"value Inserted"<<it->data<<endl;
}
void deleteValue(ll value){
    node *it;
    it=root;
    do{
        ll parity = value%2LL;
        value/=10LL;
        if(parity==0LL){
            it=it->zero;
        }else{
            it=it->one;
        }
    }while(value);
    it->data-=1LL;
   // cout<<"value Deleted"<<it->data<<endl;
}
ll matchPattern(ll pattern){
    ll ans=0LL;
    node *it;
    it=root;
    do{
        ll parity = pattern%2LL;
        pattern/=10LL;
        if(parity==0LL){
            it=it->zero;
        }else{
            it=it->one;
        }
    }while(pattern && it!=NULL);
    while(it!=NULL){
        ans=ans+it->data;
        it=it->zero;
    }
      //  cout<<"Fetched Answer"<<endl;
    return ans;
}
int main(){
    ll Q; cin >> Q ; while(Q--){
        char c;
        ll value;
        cin >> c >> value;
        switch(c){
            case '+' :
                insertValue(value);
            break;
            case '-':
                deleteValue(value);
            break;
            case '?':
                cout<<matchPattern(value)<<endl;
            break;
        }
    }return 0;
}
