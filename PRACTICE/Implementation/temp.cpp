#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> binary(ll N){
    vector<ll> ans; ans.clear();
    for(int i=0;i<32;i++,N/=2LL)
        ans.push_back(N%2LL);
    reverse(ans.begin(),ans.end());
    return ans;
}
typedef struct Node {
    struct Node *zero;
    struct Node *one;
} node;
node* getNode(){
    node* temp = (node*)malloc(sizeof(node));
    temp->one = temp->zero = NULL;
    return temp;
}
node* insert(node* root,ll val){
    node*temp = root;
    vector<ll> value = binary(val);
    for(int i=0;i<value.size();i++){
        if(value[i]==0){
            if(root->zero==NULL)
                root->zero = getNode();
            root = root->zero;
        }else{
            if(root->one==NULL)
                root->one = getNode();
            root = root->one;
        }
    }
    return temp;
}
ll getMax(node*root){
    ll ans = 0;
    while(root){
        if(root->one){
            ans = ans*2LL+1LL;
            root = root->one;
        }else{
            ans = ans*2LL;
            root = root->zero;
        }
    }
    return ans;
}
int main(){

    ll N,M; cin >> N >> M;
    ll arr[N][M];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    ll ans = 0;
    for(int stJ=0;stJ<M;stJ++){
        vector<ll> subMat(N,0);
        for(int j=stJ;j<M;j++){
            for(int i=0;i<N;i++){
                subMat[i]^=arr[i][j];
            }
            ll curr_max = 0LL;
            for(int i=0;i<N;i++){
                ll curr = 0LL;
                for(int j=i;j<N;j++){
                    curr^=subMat[j];
                }
                curr_max = max(curr_max,curr);
            }
            /*
            for(int i=0;i<N;i++)
                cout<<subMat[i]<<" "; cout<<endl;
            node *trie=getNode();
            trie=insert(trie,0LL);

            for(int i=0;i<N;i++){
                insert(trie,subMat[i]);
                curr_max = max(curr_max,getMax(trie));
            }
            cout<<curr_max<<endl;
            */
            ans = max(ans,curr_max);
        }
    }
    cout<<ans<<endl;
    return 0;
}
