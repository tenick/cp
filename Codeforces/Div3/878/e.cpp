#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

void solve(){
    string s1, s2;
    int t, q;
    cin >> s1 >> s2 >> t >> q;

    set<int> indsMismatch;
    map<int, int> indsBlockedMismatch;
    int blockedMismatchCount = 0;

    for (int i = 0; i < s1.size(); i++){
        if (s1[i] != s2[i])
            indsMismatch.insert(i);
    }

    for (int time = 0; time < q; time++){
        //cout << "time: " << time << '\n';
        if (indsBlockedMismatch.find(time) != indsBlockedMismatch.end()){
            //cout << s1[indsBlockedMismatch[time]] << " not blocked anymore!" << '\n';
            indsBlockedMismatch.erase(time);
        }

        int query;
        cin >> query;
        if (query == 1){
            int blockPos;
            cin >> blockPos;

            if (indsMismatch.find(--blockPos) != indsMismatch.end()){
                //cout << "adding: " << s1[blockPos] << '\n';
                indsBlockedMismatch.insert({time + t, blockPos});
            }
        }
        else if (query == 2){
            int str1, s1pos, str2, s2pos;
            cin >> str1 >> s1pos >> str2 >> s2pos;

            char s1Char = str1 == 1 ? s1[--s1pos] : s2[--s1pos];
            char s2Char = str2 == 1 ? s1[--s2pos] : s2[--s2pos];
            if (str1 == 1)
                s1[s1pos] = s2Char;
            else 
                s2[s1pos] = s2Char;

            if (str2 == 1) 
                s1[s2pos] = s1Char;
            else
                s2[s2pos] = s1Char;

            // update indsMismatch if applicable
            if (s1[s1pos] != s2[s1pos])
                indsMismatch.insert(s1pos);
            else 
                indsMismatch.erase(s1pos);
            if (s1[s2pos] != s2[s2pos])
                indsMismatch.insert(s2pos);
            else 
                indsMismatch.erase(s2pos);

            //cout << "query 2: " << s1 << " | " << s2 << '\n';
        }
        else if (query == 3){
            if (indsBlockedMismatch.size() == indsMismatch.size())
                cout << "YES";
            else 
                cout << "NO";
            cout << '\n'; 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}