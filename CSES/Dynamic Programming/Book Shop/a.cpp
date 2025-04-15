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

int dpoptimized2way (int n, int x, const vector<int>& book_price, const vector<int>& page_count) {
    vector<int> dp(x+1, 0);

    for (int i = 0; i < n; i++) 
        for (int j = x; j >= 1; j--) 
            dp[j] = max(dp[j], (j >= book_price[i]) * (page_count[i] + dp[(j - book_price[i]) * (j >= book_price[i])]));

    return dp[x];
}

int dpoptimizedway(int n, int x, const vector<int>& book_price, const vector<int>& page_count) {
    vector<int> dp(x+1, 0);

    for (int i = 1; i <= n; i++) 
        for (int j = x; j >= 1; j--) 
            if (j >= book_price[i-1]) 
                dp[j] = max(dp[j], page_count[i-1] + dp[j - book_price[i-1]]);

    return dp[x];
}

int dpway(int n, int x, const vector<int>& book_price, const vector<int>& page_count) {
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= book_price[i-1]) {
                dp[i][j] = max(dp[i][j], page_count[i-1] + dp[i-1][j - book_price[i-1]]);
            }
        }
    }

    return dp[n][x];
}

int rcmemoway(int i, int x, vector<vector<int>>& memo, const vector<int>& book_price, const vector<int>& page_count) {
    if (i == book_price.size() || x <= 0)
        return 0;
    if (memo[i][x] != -1)
        return memo[i][x];

    // skip
    int ans1 = rcmemoway(i+1, x, memo, book_price, page_count);

    // take (if possible)
    int ans2 = 0;
    if (x - book_price[i] >= 0)
        ans2 = page_count[i] + rcmemoway(i+1, x - book_price[i], memo, book_price, page_count);

    return memo[i][x] = max(ans1, ans2);
}

int rcway(int i, int x, const vector<int>& book_price, const vector<int>& page_count) {
    if (i == book_price.size() || x <= 0)
        return 0;

    // skip
    int ans1 = rcway(i+1, x, book_price, page_count);

    // take (if possible)
    int ans2 = 0;
    if (x - book_price[i] >= 0)
        ans2 = page_count[i] + rcway(i+1, x - book_price[i], book_price, page_count);

    return max(ans1, ans2);
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, x;
    cin >> n >> x;

    vector<int> book_price(n);
    for (int& i : book_price) cin >> i;
    vector<int> page_count(n);
    for (int& i : page_count) cin >> i;

    //cout << rcway(0, x, book_price, page_count) << '\n';

    //vector<vector<int>> memo(n+1, vector<int>(x+1, -1));
    //cout << rcmemoway(0, x, memo, book_price, page_count) << '\n';
    
    //cout << dpway(n, x, book_price, page_count) << '\n';
    cout << dpoptimizedway(n, x, book_price, page_count) << '\n';
    //cout << dpoptimized2way(n, x, book_price, page_count) << '\n';
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

