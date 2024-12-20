#include <bits/stdc++.h>
using namespace std;

// Check whether it is a bad line
// Bad line is L | R
bool check (vector<bool>& f, vector<bool>& b, int i){
    return !f[i] && !b[i] && b[i+1];
}
int main(){
   int t;
   cin >> t;
   while (t--){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n); // Given numbers
    vector<bool> f(n); // Check whether the max till ith element is i so that it is non decreasing
    vector<char> s(n); // Original L and R
    vector<bool> b(n+1); // Map L and R to boolean values
    int x = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        x = max(x,arr[i]);
        f[i] = (x == i); 
    }
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    // R - 1, L- 0
    int cnt = 0; // Check whether the count of bad lines is 0 finally.
    for (int i = 0; i < n; i++){
        b[i+1] = (s[i] == 'R');
        //cnt += check(f,b,i);
    }

    for (int i = 1; i < n; i++){
        cnt += check(f,b,i);
    }
    for (int i = 0; i < q; i++){
        int num;
        cin >> num;
        //num --;
        cnt -= check(f,b,num-1)+check(f,b,num);
        if (b[i] == 0){
            b[i] = 1;
        }
        else {
            b[i] = 0;
        }
        cnt += check(f,b,num-1)+check(f,b,num);
    }
    if (cnt == 0){
        cout << "yes" << endl;
    }
    else {
        cout << "NO" << endl;
    }
   } 
}