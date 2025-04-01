#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n,m;
    cin >> n >> m;
    vector<priority_queue<int,vector<int>,std::greater<int>>> cards(n);
    //vector<int> firsts(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int num;
            cin >> num;
            cards[i].push(num);
        }
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++){
        p[i] = i;
    }
    sort(p.begin(),p.end(),[&](int a, int b){
        return cards[a].top() < cards[b].top();
    });
    int cnt = 0;
    int maxi = -1;
    while (cnt < n*m){
        for (int i = 0; i < n; i++){
            int ind = p[i];
            if (cards[ind].top() > maxi){
                maxi = cards[ind].top();
                cards[ind].pop();
            }
            else {
                cout << -1 << endl;
                return;
            }
            cnt ++;
        }
    }
    for (int i:p){
        cout << i+1 << " ";
    }
    cout << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        ak();
    }
}