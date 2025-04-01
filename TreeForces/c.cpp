#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n+1); // Children of v[i]
    vector<int> p(n+1);
    for (int i = 2; i <= n; i++){
        int num;
        cin >> num;
        v[num] += 1;
        p[i] = num;
        
    }
    for (int i = 1; i <= n; i++){
        if (i == 1){
            cout << 1;
        }
        else if (v[p[i]] > 1){
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << endl;
}