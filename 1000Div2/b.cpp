#include <bits/stdc++.h>
using namespace std;

#define ll long long

void diwan(){
    int n,l,r;
    cin >> n >> l >> r;
    l--; r--;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll sum = 0;
    priority_queue<int>pq;
    for (int i = 0; i <= r-l; i++){
        pq.push(arr[i]);
    }
    for (int i = r-l+1; i <= r; i++){
        if (arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    for (int i = l; i <= r; i++){
        pq.push(arr[i]);
    }
    for (int i = r+1; i < n; i++){
        if (arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    ll sumr = 0;
    while (!pq.empty()){
        sumr += pq.top();
        pq.pop();
    }
    cout << min(sum,sumr) << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        diwan();
    }
}