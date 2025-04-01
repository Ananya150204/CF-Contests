#include <bits/stdc++.h>
using namespace std;

#define ll long long

void diwan(){
    int n;
    cin >> n;
    //vector<int> even;
    //vector<int> odd;
    bool ise = false;
    bool iso = false;
    int co = 0;
    int ce = 0;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        if (num%2 == 0){
            ise = true;
            ce ++;
        }
        else {
            iso = true;
            co ++;
        }
    }
    if (!ise){
        cout << co-1 << endl;
    }
    else if (!iso){
        cout << 1 << endl;
    }
    else {
        cout << co+1 << endl;
    }
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}