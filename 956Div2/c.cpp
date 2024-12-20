#include <bits/stdc++.h>
using namespace std;

vector<int> partitions(vector<int>& a, vector<int>& b, vector<int>& c, long long sum){
    long long A = 0;
    long long B = 0;
    long long C = 0;
    int n = a.size();
    vector<int> part;
    for (int i = 0; i < n; i++){
        A += a[i];
        B += b[i];
        C += c[i];

        if (part.size() == 0 && A >= (sum+2)/3){
            part.push_back(i+1);
            A = 0; B = 0; C = 0;
        }
        else if (part.size() == 1 && B >= (sum+2)/3){
            part.push_back(i+1);
            A = 0; B = 0; C = 0;
        }
        else if (part.size() == 2 && C >= (sum+2)/3){
            part.push_back(i+1);
            A = 0; B = 0; C = 0;
        }
    }
    return part;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        long long sum = 0;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            cin >> c[i];
        }
        if (partitions(a,b,c,sum).size() == 3){
            vector<int> ans = partitions(a,b,c,sum);
            cout << 1 << " " << ans[0] << " " << ans[0]+1 << " " << ans[1] << " " << ans[1] + 1 << " " <<
            n  << endl;
        }
        else if (partitions(a,c,b,sum).size() == 3){
            vector<int> ans = partitions(a,c,b,sum);
            cout << 1 << " " << ans[0] << " " << ans[1]+1 << " " << n << " " << ans[0] + 1 << " " 
            << ans[1] << endl;
        }
        else if (partitions(b,a,c,sum).size() == 3){
            vector<int> ans = partitions(b,a,c,sum);
            cout << ans[0]+1 << " " << ans[1] << " " << 1 << " " << ans[0] << " " << ans[1]+1 << " "
            << n << endl;
        }
        else if (partitions(b,c,a,sum).size() == 3){
            vector<int> ans = partitions(b,c,a,sum);
            cout << ans[1]+1 << " " << n << " " << 1 << " " << ans[0] << " " << ans[0]+1 << " " << ans[1]
            << endl;
        }
        else if (partitions(c,a,b,sum).size() == 3){
            vector<int> ans = partitions(c,a,b,sum);
            cout << ans[0]+1 << " " << ans[1] << " " << ans[1]+1 << " " << n << " " << 1 << " " << ans[0]
            << endl;
        }
        else if (partitions(c,b,a,sum).size() == 3){
            vector<int> ans = partitions(c,b,a,sum);
            cout << ans[1]+1 << " " << n << " " << ans[0]+1 << " " << ans[1] << " " << 1 << " " << ans[0]
            << endl;
        }
        else {
            cout << -1 << endl;
        }

    }
}