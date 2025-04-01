#include <bits/stdc++.h>
using namespace std;
 
int main(){
   int t;
   cin >> t;
   while (t--){
    long n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<long> suffix;
    long sum = 0;
    for (long i = n-1; i > 0; i--){
        if (s[i] == '1'){
            sum += 1;
        }
        else {
            sum -= 1;
        }
        suffix.push_back(sum);
    }
    sort(suffix.begin(),suffix.end());
    sum = 0;
    bool flag = false;
    for (long i = suffix.size()-1; i >= 0; i--){
        if (suffix[i] <= 0){
            break;
        }
        if (sum + suffix[i] >= k){
            flag = true;
            cout << suffix.size()+1-i << endl;
            break;
        }
        else 
            sum += suffix[i];
    }
    if (!flag){
        cout << -1 << endl;
    }
   }
}