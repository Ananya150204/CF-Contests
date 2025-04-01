#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    //cout << s << endl;
    //int n = s.size();
    bool foundp = false;
    bool founds = false;

    if (s[0] == 's'){
        s[0] = '.';
    }
    if (s[n-1] == 'p'){
        s[n-1] = '.';
    }
    for (int i = 0; i < n; i++){
        if (s[i] == 'p'){
            foundp = true;
        }
        else if (s[i] == 's'){
            founds = true;
        }
    }
    if (foundp && founds){
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}