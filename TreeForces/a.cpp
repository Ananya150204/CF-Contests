#include <bits/stdc++.h>
using namespace std;

int main(){
    //int t;
    //cin >> t;
    //while (t--){
        int n;
        cin >> n;
        vector<vector<bool>> adj(n+1,vector<bool>(n+1,false));
        for (int i = 0; i < n-1; i++){
            int num1,num2;
            cin >> num1 >> num2;
            adj[num1][num2] = true;
            adj[num2][num1] = true;
        }
        bool flag = false;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i != j && adj[i][j] == false){
                    cout << i << " " << j << endl;
                    flag = true;
                    break;
                }
            }
            if (flag){
                break;
            }
        }

    }
//}