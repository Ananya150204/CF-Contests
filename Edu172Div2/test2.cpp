#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> suffix_sum(n-1, 0);
        if(s[n-1] == '1') suffix_sum[n-2] = 1;
        else suffix_sum[n-2] = -1;
        for(int i = n-2 ; i >= 1 ; i--){ // i = 0 is in first grp, its contri will be 0 anyways
            if(s[i] == '1') suffix_sum[i-1] = suffix_sum[i] + 1;
            else suffix_sum[i-1] = suffix_sum[i] - 1;
        }

        sort(suffix_sum.begin(), suffix_sum.end(), greater<>());

        int sum = 0;
        int i = 0;
        bool x = true;
        while(sum < k && i < n-1){
            if(suffix_sum[i] <= 0){
                cout << "-1" << endl;
                x = false;
                break; 
            }
            sum += suffix_sum[i];
            i++;
        }
        if(sum >= k) cout << i + 1 << endl;
        else if(x) cout << "-1" << endl;
    }
}