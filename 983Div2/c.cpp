#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());

        // Binary search to find the largest j satisfying the triangle inequality   
        int answer = n;

        for (int i = 0; i < n-1; i++){
            int left = i+1;
            int right = n-1;
            int index = i+1;
            while (left <= right){
                int mid = left + (right-left)/2;
                if (arr[i]+arr[i+1] > arr[mid]){
                    index = mid;
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            answer = min(answer, n-(index-i+1));
        }
        cout << answer << endl;
    }
}