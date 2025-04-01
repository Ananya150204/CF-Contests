#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    map<int,int> diff_neg_rating;
    map<int,int> diff_no_buy;

    for (int i = 0; i < n; i++){ // At this price the calculation changes
        diff_neg_rating[a[i]]++; // Start with 0 negative rating. With each a[i] increase it.
    }
    for (int i = 0; i < n; i++){
        diff_neg_rating[b[i]]--;
        diff_no_buy[b[i]]--; // Start with n buyers.
    }

    int total = 0;
    int num_buyers = n;
    int neg_rating = 0;

    for (auto& it : diff_neg_rating){ // all prices are there in this map
        if (neg_rating <= k) //oops 
            total = max(total,it.first*num_buyers);
        num_buyers += diff_no_buy[it.first];
        neg_rating += diff_neg_rating[it.first];
    }
    cout << total << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}