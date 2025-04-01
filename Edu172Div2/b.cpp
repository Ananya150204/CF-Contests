#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> c(n+1);
        for (int i = 0; i < n; i++){
            int num;
            cin >> num;
            c[num]++;
        }
        //sort(c.begin(),c.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,std::greater<pair<int,int>>> pq;
        for (int i = 0; i <= n; i++){
            if (c[i] > 0){
                pq.push({c[i],i});
            }
        }
        map<int,int> alice;
        int score = 0;
        int i = 0; 
        while (!pq.empty()){
            int num = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            //cout << "top" << " index" << index << " freq" << num << endl;
            if (i%2 == 0 && alice[index] == 0){
                score += 1;
                //cout << "score" << score << endl;
                //cout << "index" << index << endl;
            }
            if (i%2==0)
                alice[index]++;
            i++;
            num --;
            if (num > 0){
                pq.push({num,index});
            }
        }
        //cout << "Bonus"<< endl;
        for (auto& it : alice){
            int first = it.first;
            int sec = it.second;
            if (c[first] == sec){
                score += 1;
                //cout << "score" << score << endl;
                //cout << "index" << first << endl;
            }
        }
        cout << score << endl;
    }
    return 0;
}