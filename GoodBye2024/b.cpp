#include <bits/stdc++.h>
using namespace std;
int l[400001]; // Do not initialise here
int r[400001];
int cnt[400001];
int sum[400001];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) sum[i] = cnt[i] = 0;
    for (int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i <= n; i++){
        if (l[i] == r[i]){
            cnt[l[i]]++;
            sum[l[i]] = 1;
        }
    }
    for (int i = 2; i <= 2*n; i++){
        sum[i] += sum[i-1];
    }

    for (int i = 1; i <= n; i++){
        bool canBeUnique;
        if (l[i] == r[i]){
            canBeUnique = (cnt[l[i]] <= 1);
        }
        else {
            int singlePoints = sum[r[i]] - sum[l[i]-1];
            int lengthOfInterval = r[i]-l[i]+1;
            if (singlePoints < lengthOfInterval){
                canBeUnique = true;
            }
            else {
                canBeUnique = false;
            }
        }
        if (canBeUnique){
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}