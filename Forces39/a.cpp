#include <bits/stdc++.h>
using namespace std;

#define ll long long

void diwan(){
    int n,m,k;
    cin >> n >> m >> k; // 4 3 2
    int i = 1;
    int cnt = 0;
    int temp = m;
    while (n >= 1){
        if (i%3 == 0){
            n=n-2;
            if (n < 1){
                cout << cnt << endl;
                return;
            }
            else {
                temp = temp-k;
                if (n-1 >= 1 && temp-k < 1){
                    // Agle round main nahi marega
                    cnt ++;
                    temp = m;
                }
                else if (n-1 < 1) {
                    cout << cnt << endl; return;
                }
            }
            
        }
        else if (i%3 == 1){
            n=n-1;
            if (n < 1){
                cout << cnt << endl;
                return;
            }
            else {
                temp = temp-k;
                
                if (n-1 >= 1 && temp-k < 1){
                    // Agle round main nahi marega
                    cnt ++;
                    temp = m;
                }
                else if (n-1 < 1) {
                    cout << cnt << endl; return;
                }
            }
        }
        else if (i%3 == 2){
            n=n-1;
            if (n < 1){
                cout << cnt << endl;
                return;
            }
            else {
                temp = temp-k;
                
                if (n-2 >= 1 && temp-k < 1){
                    // Agle round main nahi marega
                    cnt ++;
                    temp = m;
                }
                else if (n-2 < 1) {
                    cout << cnt << endl; return;
                }
            }
        }
        //cout <<i << " " << n << " " << temp << " " << cnt << endl;
        i++;
    }
    cout << cnt << endl;
    return;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}