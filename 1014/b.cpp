#include <bits/stdc++.h>
using namespace std;

#define ll long long

void diwan(){
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a;
    cin >> b;

    int cnta = 0;
    int cntb = 0;
    for (int i = 0; i < n; i++){
        if (i%2 == 0){
            if (a[i] == '0'){
                cnta ++;
            }
            if (b[i] == '0'){
                cntb ++;
            }
        }
        else {
            if (a[i] == '0'){
                cntb ++;
            }
            if (b[i] == '0'){
                cnta ++;
            }
        }
    }
    if (cnta >= ceil(1.0*n/2) && cntb >= floor(1.0*n/2)){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}