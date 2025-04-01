#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,m;
    cin >> n >> m;
    int xinit = 0;
    int yinit = 0;
    int xfinal = 0;
    int yfinal = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++){
        int xi,yi;
        cin >> xi >> yi;
        x = x+xi;
        y = y+yi;
        if (i == 0){
            xinit = x;
            yinit = y;
        }
        if (i == n-1){
            xfinal = x+m;
            yfinal = y+m;
        }
    }
    cout << 2*(yfinal-yinit)+2*(xfinal-xinit) << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}