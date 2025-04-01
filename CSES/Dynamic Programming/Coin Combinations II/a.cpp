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

int bottom_up_way(int x, const vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    // base cases
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            // skip coin
            dp[i][j] = dp[i-1][j];

            // take coin (if possible)
            if (j >= coins[i - 1])
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i - 1]]) % MOD;
        }
    }

    return dp[n][x];
}

int top_down_memo_way(int i, int x, vector<vector<int>>& memo, const vector<int>& coins) {
    if (x < 0) return 0;
    if (i >= coins.size()) return 0;
    if (x == 0) return 1;
    if (memo[i][x] != -1) return memo[i][x];
    
    // take coin
    int ans = top_down_memo_way(i, x - coins[i], memo, coins);
    
    // skip coin
    ans = (ans + top_down_memo_way(i+1, x, memo, coins)) % MOD;
    
    return memo[i][x] = ans;
}

int top_down_way(int i, int x, const vector<int>& coins) {
    if (x < 0)
        return 0;
    if (x == 0) return 1;
    
    // take coin
    int ans = top_down_way(i, x - coins[i], coins);
    
    // skip coin
    ans = (ans + top_down_way(i+1, x, coins)) % MOD;

    return ans;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int& i : coins) cin >> i;

    cout << bottom_up_way(x, coins);

    //vector<vector<int>> memo(n+1, vector<int>(x+1, -1));
    //int ans = top_down_memo_way(0, x, memo, coins);

    //cout << ans << '\n';
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

