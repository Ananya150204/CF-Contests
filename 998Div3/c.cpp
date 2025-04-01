#include<bits/stdc++.h>
using namespace std;
#define ll long long
void ak(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    map<int,int> my;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        //cout << a[i] 
        my[a[i]] += 1;
    }
    int s = 0;
    for (int i = 0; i < n; i++){
        //cout << a[i] << endl;
        if (a[i] != k-a[i] && my.find(a[i]) != my.end() && my.find(k-a[i]) != my.end()){
            my[a[i]]--;
            my[k-a[i]]--;
            s++;
            //cout << a[i] << " " << k-a[i] << endl;
            if (my[a[i]] == 0){
                my.erase(a[i]);
            }
            if (my[k-a[i]] == 0){
                my.erase(k-a[i]);
            }
        }
        else if (a[i] == k-a[i] && my.find(k-a[i]) != my.end()){
            if (my[a[i]] >= 2){
                my[a[i]]--;
                my[k-a[i]]--;
                s++;
                if (my[a[i]] == 0){
                    my.erase(a[i]);
                }
            }
        }
    }
    cout << s << endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        ak();
    }
}