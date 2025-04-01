#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        cout << 1 << " " << s.size() << " ";
        bool zer = false;
        int ind = -1;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '0' && zer == false){
                zer = true;
                ind = i+1;
                //break;
            }
        }
       
        if (zer){ // ind par 0 mila hai
            //cout << ind-1 << " " << - 1 + s.size() << endl; // opt 1
            //cout << 1 << " " << s.size()-1-ind << endl; // opt 2 
            string temp1 = "";
            string temp2 = "";
            bool opt1 = true;
            for (int i = 0; i < ind-1; i++){
                temp1 += '0';
                temp2 += '0';
            }
            temp1 += s.substr(ind-2,s.size()-ind+1);
            //cout << temp1 << endl;
            temp2 += s.substr(0, s.size()-ind+1);
            //cout << temp2 << endl;
            for (int i = 0; i < s.size(); i++){
                int c1 = 0;
                int c2 = 0;
                int c3 = 0;
                //cout << "At index " << i << " " << s[i] << endl;
                if (s[i] == '1'){
                    //cout << i << endl;
                    c1 = 1;
                }
                if (temp1[i] == '1'){
                    c2 = 1;
                }
                if (temp2[i] == '1'){
                    c3 = 1;
                }
                if ((c1^c2) > (c1^c3)){
                    opt1 = true;
                    break;
                }
                else if ((c1^c2) < (c1^c3)){
                    // cout << i << endl;
                    // cout << c1 << " " << c2 << " " << c3 << endl;
                    // cout << (c1^c2) << " " << (c1^c3) << endl;
                    opt1 = false;
                    break;
                }
            }
            if (opt1){
                cout << ind-1 << " " << - 1 + s.size() << endl; // opt 1
            }
            else {
                cout << 1 << " " << s.size()+1-ind << endl; // opt 2 
            }
        }
        else {
            cout << 1 << " " << 1 << endl;
        }
    }
}