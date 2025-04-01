#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPossible (ll a, ll b, ll c){
    int rem = b-a;
    float x = rem/2.0;
    return c*c > x*x;
}
void diwan(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for (int i = 0; i <= n-4; i++){
        if (arr[i] == arr[i+1] && arr[i+1] == arr[i+2] && arr[i+2] == arr[i+3]){
            cout << arr[i] << " " << arr[i] << " " << arr[i] << " " << arr[i] << endl;
            return;
        }
    }
    bool dis = true;
    bool onep = false;
    bool secp = false;
    ll p1;
    ll p2;
    vector<bool> done(n,false);
    for (int i = 0; i < n-1; i++){
        if (arr[i] == arr[i+1] && !onep){
            dis = false;
            onep = true;
            p1 = arr[i];
            done[i] = true;
            done[i+1] = true;
            i++;
        }
        else if (arr[i] == arr[i+1] && onep){
            dis = false;
            secp = true;
            p2 = arr[i];
            done[i] = true;
            done[i+1] = true;
            i++;
        }
    }
    if (dis){
        cout << -1 << endl;
    }
    else if (secp){
        cout << p1 << " " << p1 << " " << p2 << " " << p2 << endl;
    }
    else {
        for (int i = 0; i < n; i++){
            if (!done[i]){
                if (!done[i+1]){
                    if (isPossible(arr[i],arr[i+1],p1)){
                        cout << arr[i] << " " << p1 << " " << p1 << " " << arr[i+1] << endl;
                        return;
                    }
                }
                else {
                    if (isPossible(arr[i],arr[i+3],p1)){
                        cout << arr[i] << " " << p1 << " " << p1 << " " << arr[i+3] << endl;
                        return;
                    }
                }
            }
        }
        cout << -1 << endl;
    }
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}