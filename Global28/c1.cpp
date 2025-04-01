#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
    string s;
    cin >> s;
    cout << 1 << " " << s.size() << " ";
    int i = 0;
    while (i < s.size()){
        if (s[i] == '0'){
            break;
        }
        i++;
    }
    if (i == s.size()){
        cout << 1 << " " << 1 << endl;
        return;
    }
    int len = s.size()-i;
    // Credits to 
    // https://codeforces.com/contest/2048/submission/297286607
    vector<pair<string,pair<int,int>>> v; // Store all the possible strings
    for (int j = 0; j < s.size()-len; j++){
        string ans = "";
        for (int k = 0; k < len; k++){
            if (s[j+k] == s[i+k]){
                ans += '0';
            }
            else {
                ans += '1';
            }
        }
        v.push_back({ans,{j, j+len-1}});
    }
    auto it = *max_element(v.begin(),v.end());
    cout << it.second.first+1 << " " << it.second.second+1 << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}