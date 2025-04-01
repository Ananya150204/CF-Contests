#include<bits/stdc++.h>
using namespace std;
#define ll long long

// zu can't add first and remove later in g. It fails on the given tc1.
void dfs(int i, vector<set<int>>& adj, vector<bool>& vis, vector<int>& cind,
int c){
    vis[i] = true;
    cind[i] = c;
    set<int> neigh = adj[i];
    for (auto& it : neigh){
        if (!vis[it]){
            dfs(it,adj,vis,cind,c);
        }
    }
}
void ak(){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    vector<pair<int,int>> p;
    vector<set<int>> adjf(n+1);
    for (int i = 0; i < m1; i++){
        int f,s;
        cin >> f >> s;
        //f--;s--;
        p.push_back({f,s});
        adjf[f].insert(s);
        adjf[s].insert(f);
    }
    vector<set<int>> adjg(n+1);
    int cnt = 0;
    for (int i = 0; i < m2; i++){
        int f,s;
        cin >> f >> s;
        //f--;s--;
        adjg[f].insert(s);
        adjg[s].insert(f);
    }

    vector<bool> visg(n+1,false);
    vector<int> cind (n+1);
    int cg = 1;
    for (int i = 1; i <= n; i++){
        if (!visg[i]){
            dfs(i,adjg,visg,cind,cg);
            cg++;
        }
    }
    int numg = cg-1;
    for (int i = 0; i < p.size(); i++){
        int fv = p[i].first;
        int sv = p[i].second;
        if (cind[fv] != cind[sv]){
            adjf[fv].erase(sv);
            adjf[sv].erase(fv);
            cnt ++;
        }
    }
    // Jo g main nahi the wo ab f main bhi nahi hai.

    vector<bool> visf(n+1,false);
    vector<int> cind1 (n+1);
    int cf = 1;
    for (int i = 1; i <= n; i++){
        if (!visf[i]){
            dfs(i,adjf,visf,cind1,cf);
            cf++;
        }
    }
    int numf = cf-1;

    cout << cnt + numf-numg << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        ak();
    }
}