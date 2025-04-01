#include <bits/stdc++.h>
using namespace std;
//  Simply Picking “Largest Degree,
// Then Re-sort, Then Next Largest” Does Not Guarantee the Max Components
#define ll long long

void dfs(int ind, vector<vector<int>>& adj, vector<bool>& isVis){
    isVis[ind] = true;
    //cout << ind << " ";
    vector<int> n = adj[ind];
    for (int i = 0; i < n.size(); i++){
        if (!isVis[i]){
            if (n[i] == 1){
                dfs(i,adj,isVis);
            }
        }
    }
}
void diwan(){
    int n;
    cin >> n;
    set<pair<int,int>> edges;
    vector<pair<int,int>> deg;
    vector<int> degrees(n+1,0);
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        edges.insert({a,b});
        edges.insert({b,a}); // Forgot
        degrees[a]++; degrees[b]++;
    }
    for (int i = 1; i <= n; i++){
        deg.push_back({degrees[i],i});
    }
    sort(deg.begin(),deg.end(),[&](pair<int,int> a, pair<int,int> b){
        if (a.first > b.first){
            return true;
        }
        else if (a.first < b.first){
            return false;
        }
        return a.second < b.second;
    });
    int ans = -1;
    for(auto& it : edges){
        int a = it.first;
        int b = it.second;
        ans = max(ans,degrees[a]+degrees[b]-2);
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (edges.find({deg[i].second,deg[j].second}) == edges.end()){
                ans = max(ans,degrees[deg[i].second]+degrees[deg[j].second]-1);
                break;
            }
        }
    }
    cout << ans << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}