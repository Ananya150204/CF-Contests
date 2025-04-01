#include <bits/stdc++.h>
using namespace std;

#define ll long long

void diwan(){
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> s;
    bool dup = false;
    bool allSame = true;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (n > 1 && i != 0 && a[i] != a[0]){
            allSame = false;
        }
        if (s.find(a[i]) != s.end()){
            dup = true;
        }
        s.insert(a[i]);
    }
    if (n==1){
        cout << 1 << " " << n << endl;
        return;
    }
    if (!dup){
        cout << 1 << " " << n << endl;
        return;
    }
    if (allSame){
        cout << 0 << endl;
        return;
    }
    int ansl = 0;
    int ansr = 0;
    unordered_map<int,int> ele;
    vector<bool> distinct(n,true);
    for (int i = 0; i < n; i++){
        if (ele.find(a[i]) != ele.end()){
            int ind = ele[a[i]];
            distinct[ind] = false;
            distinct[i] = false;
            //ele[a[i]] = i;
        }
        ele[a[i]] = i;
    }
    int maxi = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (distinct[i]){
            if (cnt == 0){
                ansl = i;
            }
            cnt ++;
        }
        else {
            if (cnt > maxi){
                maxi = cnt;
                ansr =  i-1;
            }
            cnt = 0;
        }
    }
    if (distinct[n-1]){
        if (cnt > maxi){
                maxi = cnt;
                ansr =  n-1;
            }
    }
    cout << ansl+1 << " " << ansr+1 << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}