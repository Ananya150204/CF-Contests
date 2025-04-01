#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxi = 200001;
vector<vector<int>> tree(maxi);
int diameter = 0;
int firstEnd = 0;

void dfs(int node,int par=0, int d=0){
    if (d > diameter){
        diameter = d;
        firstEnd = node;
    }
    for (auto neigh : tree[node]){
        if (par != neigh){
            dfs(neigh,node,d+1);
        }
    }
}

void find_dia(){
    dfs(1); // Gets u one end of the diameter
    dfs(firstEnd);
}
void solve(){
    int n;
    cin >> n;
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        tree[u].push_back(v);
        tree[v].push_back(u);
        if (w > 0){
            pos.push_back(w);
        }
        else {
            neg.push_back(w);
        }
    }
    find_dia();
    sort(pos.rbegin(),pos.rend());
    sort(neg.rbegin(),neg.rend()); // Smallest neg value in front
    // An important corner case : What if everything is negative
    if (pos.size() == 0){
        cout << neg[0] << endl;
        return;
    }
    vector<int> fin; // This will store the value corresponding to the number of edges
    for (int i = 0; i < n; i++){
        if (i%2 == 0){
            if (i/2 == pos.size()){
                fin.pop_back(); // The last added num would be neg. So remove it
                break;
            }
            else {
                fin.push_back(pos[i/2]);
            }
        }
        else {
            if (i/2 == neg.size()){
                break;
            }
            else {
                fin.push_back(neg[i/2]);
            }
        }
    }

    int sz = fin.size();
    for (int i = 1; i < sz; i++){
        fin[i] += fin[i-1];
    }
    // fin has all the edges in the most optimal order.
    int ans = fin[0];
    for (int i = 1; i < min(sz,diameter); i++){
        ans = max(ans,fin[i]);
    }
    cout << ans << endl;
}

int32_t main(){
    int t=1;
    //cin >> t;
    
    while (t--){
        solve();
    }
}
