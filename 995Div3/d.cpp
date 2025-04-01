#include <bits/stdc++.h>
using namespace std;
#define int long long

int find1 (vector<int>& arr, int i, int j, int val){
    int start = i-1;
    int end = j;
    int ans = -1;
    int mid = (start+end)/2;
    while (start <= end){
        mid = (start+end)/2;
        if (arr[mid] >= val){
            ans = mid;
            end--;
        }
        else {
            start++;
        }
    }
    return ans;
}
int find (vector<int>& arr, int i, int j, int val){
    int start = i;
    int end = j-1;
    int ans = -1;
    int mid = (start+end)/2;
    while (start <= end){
        mid = (start+end)/2;
        if (arr[mid] <= val){
            ans = mid;
            start ++;
        }
        else {
            end --;
        }
    }
    return ans;
}
void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum < x){
        cout << 0 << endl;
        return;
    }
    sort (a.begin(),a.end());
    x = sum-x;
    y = sum-y;
    // y <= a[i]+a[j] <= x
    int res = 0;
    for (int i = 0; i < n; i++){
        int l = lower_bound(a.begin(),a.end(),y-a[i])-a.begin();
        int r = upper_bound(a.begin(),a.end(),x-a[i])-a.begin();
        res += max(0ll,r-l);
        if (i >= l && i < r) {
            res--;
        }
    }
    cout << res/2 << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}