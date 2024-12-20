#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 0;
        bool flag = true;
        for (int i = 0; i < n; i++){
            flag = true;
            for (int j = 0; j < n; j++){
                if (j != i && abs(a[j]-a[i])%k == 0){
                    //cout << a[j] << " " << 
                    flag = false;
                    break;
                }
            }
            if (flag){
                ans = i+1;
                break;
            }
        }
        if (flag){
            cout << "YES"<< endl;
            cout << ans << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}