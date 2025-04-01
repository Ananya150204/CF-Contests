#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
      int n;
      cin >> n;
      vector<int> a(n);
      bool allZero = true;
      bool allNon = true;
      bool oneZero = false;
      bool oneNon = false;
      bool moreNon = false;
      for (int i = 0; i < n; i++)  {
        cin >> a[i];
        if (a[i] == 0){
            oneZero = true;
            allNon = false;
        }
        else if (a[i] != 0 && !oneNon){
            allZero = false;
            oneNon = true;
        }
        else if (a[i] != 0 && oneNon){
            moreNon = true;
        }
      }
      if (allZero){
        cout << 0 << endl;
      }
      else if (allNon){
        cout << 1 << endl;
      }
      else if (oneNon && !moreNon){
        cout << 1 << endl;
      }
      else {
        // Non zeros consec
        bool first = false;
        bool second = false;
        bool consec = true;
        for (int i = 0; i < n; i++){
            if (a[i] != 0 && !first){
                first = true;
            }
            else if (a[i] == 0 && first && !second){
                second = true;
            }
            else if (a[i] != 0 && first && second){
                consec = false;
                break;
            }
        }
        if (consec){
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
      }
    }
}