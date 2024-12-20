#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >> n;
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++){
            int num = 0;
            cin >> num;
            if (num == 0){
                cnt0 ++;
            }
            else {
                cnt1 ++;
            }
        }
        int maxi = min(cnt0,cnt1);
        int mini = 0;
        if (cnt0 %2 == 0 && cnt1 % 2 == 0){
            mini = 0;
        }
        else {
            mini = 1;
        }
        cout << mini << " " << maxi << endl;
    }
}