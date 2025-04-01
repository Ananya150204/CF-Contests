#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++){
        if (a[i] <= a[i+1]){
            a[i+1] -= a[i];
            a[i] = 0;
        }
    }
    //bool flag = true;
    for (int i = 0; i < n-1; i++){
        if (a[i+1] < a[i]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        ak();
    }
}