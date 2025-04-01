#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n);
    if ((y == x+1) || (x == 1 && y == n)){
        if (n%2 == 0){
            a[0] = 0;
            for (int i = 1; i < n; i++){
                a[i] = 1 - a[i-1];
            }
        }
        else {
            a[0] = 0;
            for (int i = 1; i < n-1; i++){
                a[i] = 1 - a[i-1];
            }
            a[n-1] = 2;
        }
    }
    else {
        x--;
        y--;
        a[x] = 0;
        a[y] = 1;
        for (int i = x+1; i < y; i++){
            a[i] = 1 - a[i-1];
        }
        if (a[y-1] == a[y]){ // Odd length cycle
            a[y-1] = 2; 
        }
        for (int i = (y+1)%n; i != x%n; i = (i+1)%n){
            a[i%n] = 1 - a[((i-1)%n+n)%n];
        }
        if (a[((x-1)%n+n)%n] == a[x%n]){ // Odd
            a[((x-1)%n+n)%n] = 2;
        }
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}