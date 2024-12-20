#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string n;
        cin >> n;
        int cnt2 = 0;
        int cnt3 = 0;
        unsigned long long sum = 0;
        //cout << n << endl;
        int s = n.size();
        int i = s-1;
        while (i >= 0){
            //cout << "Inside loop" << endl;
            int rem = n[i]-48;
            //cout << rem;
            //cout << rem << endl;
            if (rem == 2){
                cnt2++;
            }
            else if (rem == 3){
                cnt3++;
            }
            sum += rem;
            //cout << sum << endl;
            i--;
        }
        bool flag = false;
        for (int i = 0; i <= cnt2; i++){
            long temp = sum + 2*i;
            // Must be divisible by 3 as 6*y can't help with 3
            if (temp%3 == 0){ // Now check with 9 - only 3 possible cases 0,3,6
                if (temp%9 == 0){
                    flag = true;
                    break;
                }
                else if (temp%9 == 3){ // 6*y % 9 == 6
                    if (cnt3 >= 1){
                        flag = true;
                        break;
                    }
                }
                else {
                    if (cnt3 >= 2){
                        flag = true;
                        break;
                    }
                }

            }
        }
        if (flag){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
    }
}