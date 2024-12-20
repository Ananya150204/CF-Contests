#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string a,b,c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++){
            dp[i+1][0] = dp[i][0] + (a[i] != c[i]);
        }
        for (int j = 0; j < m; j++){
            dp[0][j+1] = dp[0][j] + (b[j] != c[j]);
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                int ans1 = INT_MAX;
                int ans2 = INT_MAX;
                if (a[i-1] != c[i+j-1]){
                    ans1 = dp[i-1][j]+1;
                }
                else {
                    ans1 = dp[i-1][j];
                }
                if (b[j-1] != c[i+j-1]){
                    ans2 = dp[i][j-1]+1;
                }
                else {
                    ans2 = dp[i][j-1];
                }
                dp[i][j] = min(ans1,ans2);
            }
        }
        cout << dp[n][m] << endl;
    }
}