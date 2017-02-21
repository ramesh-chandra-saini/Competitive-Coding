#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> score(n);
    for(int score_i = 0; score_i < n; score_i++){
       cin >> score[score_i];
    }
    int low = score[0];
    int high = score[0];
    int l=0,h=0;
    for(int i=0;i<n;i++){
        if(low>score[i])
            l++,low = score[i];
        if(high<score[i])
            h++,high = score[i];
    }
    cout<<h<<" "<<l<<endl;
    return 0;
}
