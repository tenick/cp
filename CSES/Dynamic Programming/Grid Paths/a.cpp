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

int bottom_up_way(int n, const vector<vector<char>>& grid) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    dp[1][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) * (grid[i-1][j-1] != '*') % MOD;

    return dp[n][n];
}

int top_down_memo_way(int i, int j, vector<vector<int>>& memo, const vector<vector<char>>& grid) {
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0 || grid[i][j] == '*')
        return -1;
    if (memo[i][j] != -1)
        return memo[i][j];
    
    int res = 0;
    int moveDown = top_down_memo_way(i-1, j, memo, grid);
    if (moveDown != -1) res = (res + moveDown) % MOD; 
    int moveRight = top_down_memo_way(i, j-1, memo, grid);
    if (moveRight != -1) res = (res + moveRight) % MOD;

    return memo[i][j] = res;
}

int top_down_way(int i, int j, const vector<vector<char>>& grid) {
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0 || grid[i][j] == '*')
        return -1;
    
    int res = 0;
    int moveDown = top_down_way(i-1, j, grid);
    if (moveDown != -1) res = (res + moveDown) % MOD; 
    int moveRight = top_down_way(i, j-1, grid);
    if (moveRight != -1) res = (res + moveRight) % MOD;

    return res;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (auto& row: grid) {
        for (auto& c : row) cin >> c;
    }

    cout << bottom_up_way(n, grid) << '\n';
    //cout << top_down_way(n-1, n-1, grid) << '\n';
    //vector<vector<int>> memo(n, vector<int>(n, -1));
    //cout << top_down_memo_way(n-1, n-1, memo, grid) << '\n';
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

