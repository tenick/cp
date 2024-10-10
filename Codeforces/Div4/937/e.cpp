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

bool isPossible(int len, string& s){
    map<string, int> cnts;
    for (int i = 0; i < s.size(); i += len){
        string sub = s.substr(i, len);
        if (cnts.find(sub) == cnts.end()) cnts[sub] = 0;
        cnts[sub]++;
        if (cnts.size() > 2) return false;
    }

    if (cnts.size() == 1) return true;
    bool found = false;
    vector<string> ss;
    for (auto& kvp : cnts){
        ss.push_back(kvp.first);
        if (kvp.second == 1){
            found = true;
        }
    }
    if (!found) return false;
    int wrongs = 0;
    for (int i = 0; i < len; i++){
        wrongs += ss[0][i] != ss[1][i];
    }
    return wrongs < 2;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int possible = n;
    for (int i = 1; i <= floor(sqrt(n)); i++){
        if (n % i != 0) continue;
        if (isPossible(i, s)) {
            cout << i << '\n';
            return;
        }
        if (isPossible(n / i, s)) {
            possible = min(possible, n / i);
        }
    }
    cout << possible << '\n';
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