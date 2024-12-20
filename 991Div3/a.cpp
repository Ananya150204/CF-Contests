#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        int ans = 0;
        int sum = 0;
        cin >> n >> m;
        bool flag = false;
        for (int i = 1; i <= n; i++){
            string s;
            cin >> s;
            if (sum+s.size() < m){
                sum = sum + s.size();
            }
            else if (sum+s.size() == m && !flag){
                flag = true;
                ans = i;
                sum = sum + s.size();
            }
            else if (s.size() == 0 && sum+s.size() == m && flag){
                ans = i;
            }
            else if (sum+s.size() > m && !flag){
                flag = true;
                ans = i-1;
                sum = sum + s.size();
            }
        }
        if (flag)
            cout << ans << endl;
        else
            cout << n << endl;
    }
}