#include <bits/stdc++.h>
using namespace std;
 
long long merge(int* brr, int* crr, int b, int c,int* temp, int n){
    long long cc = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < b && j < c){
        if (brr[i] < crr[j]){
            temp[k] = brr[i];
            i++;
            k++;
        }
        else {
            temp[k] = crr[j];
            cc += (b-i);
            k++;
            j++;
        }
    }
    while (i < b){
        temp[k] = brr[i];
        k++;
        i++; 
    }
    while (j < c) {
        temp[k] = crr[j];
        k++;
        j++;
    }
    return cc;
}
 
long long count (int* arr, int n){
    if (n == 0 || n == 1){
        return 0;
    }
    long long c = 0;
    int brr[n/2];
    int crr[n-n/2];
    for (int i = 0; i < n/2; i++){
        brr[i] = arr[i];
    }
    for (int i = 0; i < n-n/2; i++){
        crr[i] = arr[i+n/2];
    }
    //int temp[n];
    c += count(brr,n/2);
    c += count(crr,n-n/2);
    c += merge(brr,crr,n/2,n-n/2,arr,n);
    return c;
}
 
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];
        int brr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++){
            cin >> brr[i];
        }
        if (count(arr,n)%2 == count(brr,n)%2){
            bool flag = true;
            sort(arr,arr+n);
            sort(brr,brr+n);
            for (int i = 0; i < n; i++){
                if (arr[i] != brr[i]){
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << "yes" << endl;
            else 
                cout << "no" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}