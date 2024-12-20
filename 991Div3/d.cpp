#include <bits/stdc++.h>
using namespace std;

char lower(char c){
    if (c == '1'){
        return '0';
    }
    else if (c == '2'){
        return '1';
    }
    else if (c == '3'){
        return '2';
    }
    else if (c == '4'){
        return '3';
    }
    else if (c == '5'){
        return '4';
    }
    else if (c == '6'){
        return '5';
    }
    else if (c == '7'){
        return '6';
    }
    else if (c == '8'){
        return '7';
    }
    else if (c == '9'){
        return '8';
    }
    return '0';
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int i = s.size()-1;
        //cout << i;
        while (i >= 1){
            if (s[i] != '0' && s[i-1] < lower(s[i])){
                char temp = s[i-1];
                s[i-1] = lower(s[i]);
                s[i] = temp ;
            }
            if (i+1 < s.size() && s[i] < lower(s[i+1])){
                i++;
            }
            else
                i--;
        }
        cout << s << endl;
    }
    
}