#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    // 1 2 4 6 8
    //sort(v.begin(),v.end());
    for (int i = 0; i < n-1; i++){
        int maxi = max(v[i],v[i+1]);
        int mini = min(v[i],v[i+1]);
        if (2*mini > maxi){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}