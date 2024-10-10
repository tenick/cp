#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;


        vector<pair<pair<bool, int>, vector<pair<bool, int>>>> trie(26, {{false, -1}, vector<pair<bool, int>>(26, {false, -1})});
        bool yes = false;
        
        for (int k = 0; k < 2; k++){
            for (int i = k; i < n - 1; i+=2){
                char c1 = s[i];
                char c2 = s[i + 1];
                if (trie[c1 - 97].first.first && trie[c1 - 97].second[c2 - 97].first
                    && !(trie[c1 - 97].first.second == i || trie[c1 - 97].first.second == i + 1)
                    && !(trie[c1 - 97].second[c2 - 97].second == i || trie[c1 - 97].second[c2 - 97].second == i + 1)){
                    yes = true;
                    break;
                }
                else{
                    trie[c1 - 97].first.first = true;
                    trie[c1 - 97].second[c2 - 97].first = true;

                    if ((trie[c1 - 97].first.second == i || trie[c1 - 97].first.second == i + 1) ||
                        (trie[c1 - 97].second[c2 - 97].second == i || trie[c1 - 97].second[c2 - 97].second == i + 1)){
                        trie[c1 - 97].first.second = trie[c1 - 97].first.second == -1 ? i : min(i, trie[c1 - 97].first.second);
                        trie[c1 - 97].second[c2 - 97].second = trie[c1 - 97].second[c2 - 97].second == -1 ? i + 1 : min(i + 1, trie[c1 - 97].second[c2 - 97].second);

                    }
                    else {
                        trie[c1 - 97].first.second = i;
                        trie[c1 - 97].second[c2 - 97].second = i + 1;
                    }

                }
            }
            if (yes) break;
        }

        if (yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}