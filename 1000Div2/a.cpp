#include <bits/stdc++.h>
using namespace std;

#define ll long long

void diwan(){
    ll l,r;
    cin >> l >> r;
    if (l == 1 && r == 1){
        cout << 1 << endl;
    }
    else {
        cout << r-l << endl;
    }
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}