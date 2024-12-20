#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        int k;
        cin >> n >> k;
        if (n == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        if (k == 1 || k == n){
            cout << -1 << endl;
            continue;
        }
        if (k%2 == 0){ // 1 2 3 4 5; k = 4
            cout << 3 << endl;
            cout << 1 << " " << k << " " << k+1 << endl;
        }
        else {
            cout << 5 << endl;
            cout << 1 << " " << k-1 << " " << k << " " << k+1 << " " << k+2 << endl;
        }
    }
}