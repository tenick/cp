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

int dpway(int a, int b) {
    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
    for (int i = 1; i <= a; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= b; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= min(a, b); i++)
        dp[i][i] = 0;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            for (int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
        }
    }

    return dp[a][b];
}

int rcway(int a, int b, vector<vector<int>>& memo) {
    if (a == 0 || b == 0 || a == b)
        return 0;
    if (memo[a][b] != -1)
        return memo[a][b];
 
    int minCut = INT_MAX;
    for (int i = 1; i < a; i++) {
        // horizontal cut
        int minCut1 = rcway(i, b, memo) + rcway(a - i, b, memo);
        minCut = min(minCut, 1 + minCut1); 
    }
    for (int i = 1; i < b; i++) {
        // vertical cut
        int minCut1 = rcway(a, i, memo) + rcway(a, b - i, memo);
        minCut = min(minCut, 1 + minCut1); 
    }
 
    return memo[a][b] = minCut;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int a, b;
    cin >> a >> b;

    cout << dpway(a, b) << '\n';
    return;

    vector<vector<int>> memo(a+1, vector<int>(b+1, -1));
    cout << rcway(a, b, memo) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}

