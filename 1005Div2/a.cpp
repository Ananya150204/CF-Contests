#include <bits/stdc++.h>
using namespace std;

#define ll long long

void diwan(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool z = false;
    bool o = false;
    for (char c : s){
        if (c=='0'){
            z = true;
        }
        else {
            o = true;
        }
    }
    if (o && !z){
        cout << 1 << endl;
    }
    else if (z && !o){
        cout << 0 << endl;
    }
    else {
        int ind = -1;
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                ind = i;
                break;
            }
        }
        int cnt = 0;
        for (int i = ind; i < n-1; i++){
            if (s[i] == '0' && s[i+1] == '1'){
                cnt++;
            }
        }
        if (s[n-1] == '1'){
            cout << 2*cnt+1 << endl;
        }
        else {
            cout << 2*cnt+2 << endl;
        }
    }
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}