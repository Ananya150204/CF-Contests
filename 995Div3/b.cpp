#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int rem = n%(a+b+c);
    int q = n/(a+b+c);
    if (rem == 0){
        cout << q*3 << endl;
    }
    else if (a >= rem){
        cout << q*3+1 << endl;
    }
    else if (a+b >= rem){
        cout << q*3+2 << endl;
    }
    else {
        cout << q*3 + 3 << endl;
    }
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}