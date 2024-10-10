#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;


    string sample = "";
    // check first if have all first k letters, if not, invalid
    set<char> seen;
    for (char c : s) seen.insert(c);
    if (seen.size() != k){
        for (int i = 0; i < k; i++){
            if (seen.find('a'+i) != seen.end())
                continue;
            for (int q = 0; q < n; q++){
                sample.push_back('a'+i);
            }
            cout << "NO\n";
            cout << sample << '\n';
            return;
        }
    }

    
    


    vector<int> charFreq(k, 0);
    for (int i = 0; i < m; i++){
        charFreq[s[i]-'a']++;
    }
    
    
    bool valid = true;
    set<char> handled;
    for (int i = 0; i < m; i++){
        charFreq[s[i]-'a']--;
        if (handled.find(s[i]) == handled.end()){
            for (int j = 0; j < k; j++){
                if (charFreq[j] < n-1){
                    valid = false;
                    sample.push_back(s[i]);
                    for (int q = 0; q < n - 1; q++){
                        sample.push_back((char)('a'+j));
                    }
                    break;
                }
            }
            if (!valid) break;
            handled.insert(s[i]);
        }
        if (!valid) break;
    }
    

    if (valid) cout << "YES\n";
    else {
        cout << "NO\n";
        cout << sample << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}