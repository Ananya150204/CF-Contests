#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int cnt0 = 0;
    int op = 0;
    while (cnt < n){
        if (s[cnt] == '1'){
            cnt ++;
            cnt0 = 0;
        }
        else {
            cnt0 ++;
            if (cnt0 == m){
                cnt += k;
                op ++;
                cnt0 = 0;
            }
            else {
                cnt ++;
            }
        }
    }
    cout << op << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}