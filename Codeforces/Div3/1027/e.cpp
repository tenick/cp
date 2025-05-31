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

vector<ll> max1(1, LLONG_MIN/2);
vector<ll> max2(1, LLONG_MIN/2);
void rc(int node, int parent, vector<ll>& ans, const vector<int>& danger, const vector<vector<int>>& nodeByEdges) {
    bool even = (max1.size()-1) % 2 == 0;

    ll n1 = danger[node]*(even ? -1 : 1);
    max1.push_back(max(n1, max1.back()+n1));

    ll n2 = danger[node]*(even ? 1 : -1);
    max2.push_back(max(n2, max2.back()+n2));

    ans[node] = even ? max2.back() : max1.back();

    for (int neighbor : nodeByEdges[node]) {
        if (neighbor == parent)
            continue;
        rc(neighbor, node, ans, danger, nodeByEdges);
    }

    max1.pop_back();
    max2.pop_back();
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    vector<int> danger(n);
    max1.reserve(n);
    max2.reserve(n);
    for (int& i : danger) cin >> i;

    vector<vector<int>> nodeByEdges(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        nodeByEdges[u-1].push_back(v-1);
        nodeByEdges[v-1].push_back(u-1);
    }

    vector<ll> ans(n);
    rc(0, -1, ans, danger, nodeByEdges);

    for (ll i : ans) cout << i << ' ';
    cout << '\n';
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

