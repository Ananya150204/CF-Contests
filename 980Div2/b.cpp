#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        long long n,k;
        cin >> n >> k;
        vector<long long> a(n,0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        long long ans = k;
        long long sub = 0;
        for (long long i = 0; i < n; i++){
            a[i] -= sub;
            k -= min(k,(n-i)*a[i]);

            if (k <= 0){
                break;
            }
            ans ++; // Unsuccessful attempts
            sub += a[i];
        }
        cout << ans << endl;
    }
}