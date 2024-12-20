#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        //vector<int> arr(n,0);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;
            mini = min(mini,num);
            maxi = max(maxi,num);
        }
        cout << (n-1)*(maxi-mini) << endl;
    }
}