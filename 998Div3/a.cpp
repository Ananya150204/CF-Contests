#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    vector<int> a(5);
    for (int i = 0; i < 5; i++){
        if (i != 2)
            cin >> a[i];
        else
            a[2] = a[0]+a[1];
    }
    if (a[3] == a[1]+ a[2] && a[4] == a[3]+a[2]){
        cout << 3 << endl;
        return;
    }
    if (a[3] == a[1]+ a[2]){
        cout << 2 << endl;
        return;
    }
    if (a[4] == a[2]+a[3]){
        cout << 2 << endl;
        return;
    }
    if (a[4]-a[3] == a[3]-a[1]){
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        ak();
    }
}