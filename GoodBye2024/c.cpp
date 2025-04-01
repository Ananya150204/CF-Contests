#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
 map<int,pair<int,int>> dp;
// Store the answer for length L assuming start from 1
pair<int,int> ans(int l, int r, int k){ // sum,number of elements
    int len = r-l+1;
    if (len < k){
        return {0,0};
    }
    if (dp.find(len) != dp.end()){
        return {dp[len].first + (l-1)*dp[len].second, dp[len].second};
    }
    if (len & 1){
        if (len != 1){
           pair<int,int> a = ans(l,l+len/2-1,k);
           pair<int,int> b = ans(l+len/2+1,r,k);
           // Add the contribution of the middle element
           pair<int,int> lr = {a.first + b.first + l + len/2, a.second + b.second + 1};
           dp[len] = {lr.first - (l-1)*lr.second,lr.second};
           return lr;
        }
        else {
            dp[1] = {1,1};
            return {l,1}; // A single element 
        }
    }
    else {
        pair<int,int> a = ans(l,l+len/2-1,k); // 2 + 4/2 - 1
        pair<int,int> b = ans(l+len/2,r,k);
        pair<int,int> lr = {a.first + b.first, a.second + b.second};
        dp[len] = {lr.first - (l-1)*lr.second,lr.second};
        return lr;
    }
}
void solve(){
    int n,k;
    cin >> n >> k;
    dp.clear();
    cout << ans(1,n,k).first << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}