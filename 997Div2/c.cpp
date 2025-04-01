#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin >> n;
    if (n == 6){ // Directly from given example;
        cout << 1 << " " << 1 << " " << 2 << " " << 3 << " " << 1 << " " << 2 << endl;
        return;
    }
    cout << 1 << " " << 2 << " ";
    //int k = 3;
    // 2*(n-3) > n
    for (int k = 3; k <= n-2; k++){
        cout << k << " ";
    }
    cout << 1 << " " << 2 << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}