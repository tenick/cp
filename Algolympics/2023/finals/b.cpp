#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;

char cipher(char c, int k){
    int pos = c - 'a';
    int newPos = pos - k;
    if (newPos < 0) newPos = 26 + newPos;
    return 'a' + newPos;
}

string wCihper(string& s, int k){
    string newS=s;
    for (int i = 0; i < s.size(); i++){
        newS[i] = cipher(s[i], k);
    }
    return newS;
}

void solve(){
    int n;
    cin >> n;

    set<string> wahList;
    for (int i = 0; i < n; i++){
        string wahw;
        cin >> wahw;
        wahList.insert(wahw);
    }

    int e;
    cin >> e;
    set<string> encr;
    for (int i = 0; i < e; i++){
        string wahw;
        cin >> wahw;
        encr.insert(wahw);
    }

    int minAns = -1;
    for (int i = 1; i < 70; i++){
        int matchCount = 0;
        set<string> done;

        for (string word : encr){
            string decoded = wCihper(word, i);
            
            if (wahList.find(decoded) != wahList.end() && done.find(decoded) == done.end()) {
                matchCount++;
                done.insert(decoded);
            }
        }

        if (matchCount >= wahList.size()){
            minAns = i;
            break;
        }
    }
    cout << minAns << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}