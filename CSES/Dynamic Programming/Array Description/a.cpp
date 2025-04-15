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

int bottom_up_way(int n, int m, const vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(m+1, 0));

    // base case
    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }
    else 
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
                if (j+1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
        else {
            dp[i][arr[i]] = (dp[i-1][arr[i]-1] + dp[i-1][arr[i]]) % MOD;
            if (arr[i]+1 <= m)
                dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i]+1]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n-1][i]) % MOD;
    }

    return ans;
}

int top_down_memo_way(int i, int val, int m, vector<vector<int>>& memo, const vector<int>& arr) {
    if (val < 1 || val > m)
        return 0;

    if (arr[i] == 0 || val == arr[i]){
        if (i == 0)
            return 1;
        if (memo[i][val] != -1)
            return memo[i][val];

        int ans = 0;
        for (int j = 0; j < 3; j++) {
            ans = (1ll * ans + top_down_memo_way(i-1, val + 1 - j, m, memo, arr)) % MOD;
        }
        return memo[i][val] = ans; 
    }
    else return 0;
}

int top_down_way(int i, int val, int m, const vector<int>& arr) {
    if (val < 1)
        return 0;

    if (arr[i] == 0 || val == arr[i]){
        if (i == 0)
            return 1;
        return top_down_way(i-1, val-1, m, arr) + top_down_way(i-1, val, m, arr) + top_down_way(i-1, val+1, m, arr);
    }
    else return 0;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    
    //int ans = 0;
    //for (int i = 1; i <= m; i++) {
        //ans += top_down_way(n-1, i, m, arr);
    //}

    //int ans = 0;
    //vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
    //for (int i = 1; i <= m; i++) {
        //ans = (1ll * ans + top_down_memo_way(n-1, i, m, memo, arr)) % MOD;
    //}

    cout << bottom_up_way(n, m, arr) << '\n';
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

