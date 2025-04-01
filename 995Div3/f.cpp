#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> merge(vector<pair<int,int>> ranges){
    vector<pair<int,int>> ans;
    sort(ranges.begin(),ranges.end());

    for (int i = 0; i < ranges.size(); i++){
        if (ans.empty()||ans.back().second < ranges[i].first){ // it is a different range
            ans.push_back({ranges[i].first,ranges[i].second});
        }
        else {
            ans.back().second = max(ans.back().second,ranges[i].second);
        }
    }
    return ans;
}

vector<pair<int,int>> apply(int ind, int n, vector<pair<int,int>> ranges){
    vector<pair<int,int>> newr;
    for (auto [l,r] : ranges){
        if (l <= ind && ind <= r){
            if (l < ind || ind < r){
                newr.push_back({l,r});
            }
            newr.push_back({1,1});
            newr.push_back({n,n});
        }
        else if (ind < l){
            newr.push_back({l-1,r});
        }
        else {
            newr.push_back({l,r+1});
        }
    }
    return merge(newr);
}

int get_possibilities(vector<pair<int,int>> ranges){
    int tot = 0;
    for (auto& it : ranges){
        int l = it.first;
        int r = it.second;
        tot += (r-l+1);
    }
    return tot;
}
void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<pair<int,int>> ranges;
    ranges.push_back({m,m});
    for (int i = 0; i < q; i++){
        int num;
        cin >> num;
        ranges = apply(num,n,ranges);
        cout << get_possibilities(ranges) << " ";
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