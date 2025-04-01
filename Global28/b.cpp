#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        if (k == 1){
            for (int i = 1; i <= n; i++ ){
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            vector<int> v(n+1,0);
            unordered_set<int> s;
            int x = 1;
            for (int i = k; i <= n; i+=k){
                v[i] = x;
                s.insert(x);
                x ++;
            }
            x = n;
            for (int i = n; i >= 0; i--){
                if (v[i] == 0 && s.find(x) == s.end()){
                    v[i] = x;
                    //cout << i << " ";
                    x--;
                }
                else if (v[i] == 0 && s.find(x) != s.end()) {
                    v[i] = --x;
                    x--;
                }
                //x --;
            }
            
            for (int i = 1; i <= n; i++){
                 cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}