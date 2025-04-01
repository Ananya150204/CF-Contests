#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;cin >> n >> m;
    vector<string> s(n+1);
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] = "-" + s[i]; // Modify for one based indexing
    }
    vector<pair<int,int>> jda[n+2][m+2];

    // Create reverse adjacency list
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s[i][j] == 'U'){
                jda[i-1][j].push_back({i,j});
            }
            else if (s[i][j] == 'L'){
                jda[i][j-1].push_back({i,j});
            }
            else if (s[i][j] == 'R'){
                jda[i][j+1].push_back({i,j});
            }
            else if (s[i][j] == 'D'){
                jda[i+1][j].push_back({i,j});
            }
        }
    }
    queue<pair<int,int>> q;
    bool isVis[n+2][m+2] = {false};

    // Insert all the boundary cells
    for (int i = 0; i <= m+1; i++){
        q.push({0,i});
        isVis[0][i] = true;
    }
    for (int i = 1; i <= n+1; i++){
        q.push({i,0});
        isVis[i][0] = true;
    }
    for (int i = 1; i <= m+1; i++){
        q.push({n+1,i});
        isVis[n+1][i] = true;
    }
    for (int i = 1; i <= n; i++){
        q.push({i,m+1});
        isVis[i][m+1] = true;
    }

    // Perform BFS.
    while (!q.empty()){
        pair<int,int> fr = q.front();
        q.pop();
        vector<pair<int,int>> neigh = jda[fr.first][fr.second];

        for (auto& it : neigh){
            if (!isVis[it.first][it.second]){
                q.push({it.first,it.second});
                isVis[it.first][it.second] = true;
            }
            
        }
    }

    // Check the unspecified cells.

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s[i][j] == '?' && isVis[i][j] == false){
                if (isVis[i+1][j] && isVis[i-1][j] && isVis[i][j+1] && isVis[i][j-1]){
                    isVis[i][j] = true;
                }
            }
        }
    }

    // Count the cells which are not visited (and hence in loop)

    int ans = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (isVis[i][j] == false){
                ans ++;
            }
        }
    }

    cout << ans << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}