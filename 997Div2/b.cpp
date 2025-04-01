#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n,vector<int>(n));
    for (int i = 1; i <= n; i++){
        //int cnt = 0;
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++){
            if (s[j-1] == '1'){
                adj[i-1][j-1] = 1;
            }
        }
        //num_ones.push_back({cnt,i});
    }
    // sort(num_ones.begin(),num_ones.end(),[](pair<int,int> a, pair<int,int> b){
    //     if (a.first > b.first){
    //         return true;
    //     }
    //     else if (a.first < b.first){
    //         return false;
    //     }
    //     else {
    //         return a.second < b.second;
    //     }
    // });
    // for (auto& i : num_ones){
    //     cout << i.first << " " << i.second;
    //     cout << endl;
    // }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = i;
    }
    sort(ans.begin(),ans.end(),[&](int x, int y){
        if (adj[x][y] == 1){
            return x < y;
        }
        return x > y;
    });
    for (int i : ans){
        cout << i+1 << " ";
    }
    cout << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}