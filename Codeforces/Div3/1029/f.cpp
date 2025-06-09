#include <climits>
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

template <typename T> inline T iceil(T a, T b) {
    return (a + b - 1) / b;
}

#define MOD_ANSWER
#ifdef MOD_ANSWER
constexpr int MOD = 1e9 + 7;
#endif
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2){
            res *= a;
#ifdef MOD_ANSWER
            res %= MOD;
#endif
        } 
        a *= a;
#ifdef MOD_ANSWER
        a %= MOD;
#endif
        b /= 2;
    }
    return res;
}

int leavesCnt(int node, int parent, const vector<vector<int>>& nodeByEdges) {
    bool isLeaf = true;
    int cnt = 0;
    for (int child : nodeByEdges[node]) {
        if (child == parent) continue;
        isLeaf = false;
        cnt += leavesCnt(child, node, nodeByEdges);
    }

    if (isLeaf) cnt++;
    return cnt;
}

// <child count, special total>
tuple<ll , ll> calc(int node, int parent, const vector<vector<int>>& nodeByEdges) {
    ll directSubtreesCnt = 0;
    ll total = -1;
    ll totalNodes = 1;
    for (int child : nodeByEdges[node]) {
        if (child == parent) continue;
        directSubtreesCnt++;
        auto [childCnt, childTotal] = calc(child, node, nodeByEdges);
        if (total == -1) {
            total = childTotal;
        }
        else {
            total = 2;
            ll diff = abs(totalNodes - 1 - childCnt);
            if (diff > 0) {
                total = (total * binpow(2, diff-1)) % MOD;
                total = (total + binpow(2, diff-1)) % MOD;
            }

        }
        totalNodes += childCnt;
    }

    if (directSubtreesCnt == 0)
        return {totalNodes, 2ll};
    return {totalNodes, ((ll)2 * total) % MOD};
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    vector<vector<int>> edges(n-1, vector<int>(2));
    for (auto& edge : edges) {
        cin >> edge[0];
        cin >> edge[1];
    }
    vector<vector<int>> nodeByEdges(n);
    for (auto& edge: edges) {
        nodeByEdges[edge[0]-1].push_back(edge[1]-1);
        nodeByEdges[edge[1]-1].push_back(edge[0]-1);
    }

    // count first no. of leaves, must be less than 2
    int leaves = leavesCnt(0, -1, nodeByEdges);
    if (leaves > 2) {
        cout << "0\n";
        return;
    }

    auto [_, total] = calc(0, -1, nodeByEdges);
    cout << total<< '\n';
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

