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

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            maxNum = max(maxNum, grid[i][j]);
        }
    }
    int maxCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxCnt += (grid[i][j] == maxNum);
        }
    }

    vector<int> rowCnts(n, 0);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += (grid[i][j] == maxNum);
        }
        rowCnts[i] = cnt;
    }
    vector<int> colCnts(m, 0);
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += (grid[j][i] == maxNum);
        }
        colCnts[i] = cnt;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int total = rowCnts[i] + colCnts[j];
            if (grid[i][j] == maxNum) total--;
            if (total == maxCnt) {
                cout << maxNum-1 << '\n';
                return;
            }
        }
    }
    cout << maxNum << '\n';
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

