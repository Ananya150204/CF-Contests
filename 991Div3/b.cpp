#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        // Odd places exchange; even places exchange
        unsigned long long even = 0;
        unsigned long long odd = 0;
        int cnt = 0;
        for (int i = 0; i < n; i=i+2){
            odd += a[i];
            cnt ++;
        }
        for (int i = 1; i < n; i=i+2){
            even += a[i];
        }
        if (odd%cnt == 0 && even%(n-cnt) == 0 && odd/cnt == even/(n-cnt)){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}