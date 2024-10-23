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

// use pos = 0, if you want to work with 1st bit of given number
template <typename T> inline bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline void bit_toggle(T& number, int pos) {
    number ^= ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline void bit_set(T& number, int pos) {
    number |= ((T)1 << pos);
}

int rc(int isImposter, int i, const vector<map<int, int>>& playerByComment, vector<int>& currState, vector<vector<int>>& memo) {
    if (memo[isImposter][i] != -1)
        return memo[isImposter][i];
    
    // update curr state
    vector<int> modified;
    for (auto& kvp : playerByComment[i]) {
        int accusation = (kvp.second + isImposter) % 2;
        if (currState[kvp.first] != -1 && currState[kvp.first] != accusation)
            return memo[isImposter][i] = -1;
        if (currState[kvp.first] == -1) {
            modified.push_back(kvp.first);
            currState[kvp.first] = accusation;
        }
    }

    int ans = 0;
    for (int j : modified) {
        int res = rc(currState[j], j, playerByComment, currState, memo);
        if (res == -1)
            return memo[isImposter][i] = -1;
        ans = max(ans, currState[i] + res);
    }

    // revert to prev state
    for (int j : modified)
        currState[j] = -1;

    return memo[isImposter][i] = ans;
}
void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> memo(2, vector<int>(n, -1));
    vector<int> currState(n, -1);
    vector<map<int, int>> playerByComment(n);
    bool possible = true;
    vector<bool> visited(n, true);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        string s; cin >> s;
        int accusation = 0;
        if (s[0] == 'i')
            accusation = 1;
        if (playerByComment[u-1].find(v-1) != playerByComment[u-1].end() && playerByComment[u-1][v-1] != accusation)
            possible = false;
        playerByComment[u-1][v-1] = accusation;
        visited[u-1] = false;
        visited[v-1] = false;
    }
    int visitCnt = 0;
    for (int i : visited) visitCnt += i;
    if (!possible) {
        cout << -1 << '\n';
        return;
    }
    currState[0] = 0;
    int a1 = rc(0, 0, playerByComment, currState, memo);
    currState[0] = 1;
    int a2 = rc(1, 0, playerByComment, currState, memo);
    if (a1 == -1 && a2 == -1) {
        cout << -1 << '\n';
        return;
    }
    for (auto& crewdp : memo) {
        for (int i : crewdp) cout << i << ' ';
        cout << '\n';
    }

    cout << max(a1, a2) + visitCnt << '\n';
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