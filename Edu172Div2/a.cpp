#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int sum = 0;
        for (int i = n-1; i >= 0; i--){
            if (sum+a[i] <= k){
                sum = sum+a[i];
            }
            else {
                break;
            }
        }
        cout << k-sum << endl;
    }
}