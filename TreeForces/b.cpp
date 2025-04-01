#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s,d;
    cin >> n >> s >> d;
    bool flag = false;
    //vector<vector<bool>> adj(n+1,vector<bool>(n+1,false));
    for (int i = 0; i < n-1; i++){
        int num1,num2;
        cin >> num1 >> num2;
        if (num1 == s && num2 == d){
            cout << "Yes" << endl;
            flag = true;
        }
        else if (num1 == d && num2 == s) {
            cout << "Yes" << endl;
            flag = true;
        }
    }
    if (!flag){
        cout << "No" << endl;
    }
    
}
