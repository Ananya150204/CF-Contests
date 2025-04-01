#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag = true;
        bool toCheck = false;
        for (int i = 0; i < n-1; i++){
            if (s[i] == 'p' && s[i+1] == 's'){
                flag = false;
                break;
            }
            else if (s[i] == 's' && s[i+1] == 'p'){
                toCheck = true;
            }
        }
        if (flag && !toCheck){
            cout << "Yes" << endl;
        }
        else if (flag && toCheck){
            int i = 1;
            vector<int> v(n);
            unordered_set<int> st;
            for (int i = 1; i <= n; i++){
                if (s[i-1] == '.'){
                    v[i-1] = n-i+1;
                    //cout << n-i+1 << endl;
                    st.insert(n-i+1);
                }
                else if (s[i-1] == 's'){
                    if (st.find(n-i+1) == st.end()){
                        v[i-1] = n-i+1;
                        st.insert(n-i+1);
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                else if (s[i-1] == 'p') {
                    int ind = i;
                    bool found = false;
                    for (int j = 1; j <= i; j++){
                        if (st.find(j) == st.end() && !found){
                            //cout << 1 << endl;
                            ind = j;
                            found = true;
                        }
                        else if (st.find(j) == st.end() && found){
                            //cout << 2 << endl;
                            //cout << j << endl;
                            flag = false;
                            break;
                        }
                    }
                    v[i-1] = ind;
                    st.insert(ind);
                    if (!flag){
                        break;
                    }
                }
            }
            // for (int i = 0; i < n; i++){
            //     cout << v[i] << " ";
            // }
            // cout << endl;
            // sort(v.begin(),v.end());
            // for (int i = 0; i < n; i++){
            //     if (v[i] != i+1){
            //         flag = false;
            //         break;
            //     }
            // }
            if (flag){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            cout << "No" << endl;
        }
    }
}