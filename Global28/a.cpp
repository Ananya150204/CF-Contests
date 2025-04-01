#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        unsigned long long int n;
        cin >> n;
        if (n%33 == 0){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}