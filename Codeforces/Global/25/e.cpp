#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;

bool isPalindrome(const string& s) {
    for (int i = 0; i < s.size()/2; i++) {
        if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

// must guarantee that there's only 2 characters in this str
bool alternatingStr(const string& s){
    char start = s[0];
    for (int i = 0; i < s.size(); i += 2){
        if (start != s[i]) return false;
    }
    start = s[1];
    for (int i = 1; i < s.size(); i += 2){
        if (start != s[i]) return false;
    }
    return true;
}

void solve(){
    string s;
    cin >> s;

    if (isPalindrome(s)) {
        vector<int> seen(26, 0);
        int charsCnt = 0;
        for (char c : s){
            if (seen[c-'a'] == 0) charsCnt++;
            seen[c-'a']++;
        }

        if (charsCnt == 1) cout << "NO\n";
        else {
            vector<int> cnts;
            for (int i : seen) {
                if (i != 0) cnts.push_back(i);
            }

            if (charsCnt == 2 
                && (alternatingStr(s) || cnts[0] == 1 || cnts[1] == 1)) // always impossible
                cout << "NO\n";
            else {
                char start = s[0];
                int i = 0;
                while (s[i] == start) i++;
                if (charsCnt == 2)
                    cout << "YES\n2\n" << s.substr(0, i+2) << " " << s.substr(i+2) << '\n';
                else 
                    cout << "YES\n2\n" << s.substr(0, i+1) << " " << s.substr(i+1) << '\n';
            }
        }
    }
    else {
        cout << "YES\n1\n";
        cout << s << '\n';
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