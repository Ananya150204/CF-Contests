#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   int n,m,k;
   cin >> n >> m >> k;
   vector<int> a(m);
   for (int i = 0; i < m; i++) {
    cin >> a[i];
   }
   unordered_set<int> q(k);
   for (int i = 0; i < k; i++) {
    int num;
    cin >> num;
    q.insert(num);
   }
   if (k < n-1){
    for (int i = 0; i < m; i++){
        cout << '0';
    }
    cout << endl;
   }
   else if (k == n){
    for (int i = 0; i < m; i++){
        cout << '1';
    }
    cout << endl;
   }
   else {
        for (int i = 0; i < m; i++){
            if (q.find(a[i]) != q.end()){
                cout << '0';
            }
            else {
                cout << '1';
            }
        }
        cout << endl;
   }
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}