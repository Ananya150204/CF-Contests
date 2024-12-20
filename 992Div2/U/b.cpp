#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int ans = 1;
        int curr = 1;
        for (;;ans++,curr = 2*curr+2){
            if (curr >= n){
                cout << ans << endl;
                break;
            }
        }
    }
}