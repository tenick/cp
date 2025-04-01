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

int top_down_way(int x, const vector<int>& coins) {
    if (x < 0) return 0;
    if (x == 0) return 1;

    int ans = 0;
    for (int coin : coins)
        ans = (ans + top_down_way(x - coin, coins)) % MOD;
    return ans;
}

int top_down_way_memo(int x, vector<int>& memo, const vector<int>& coins) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (memo[x] != -1) return memo[x];

    int ans = 0;
    for (int coin : coins)
        ans = (ans + top_down_way_memo(x - coin, memo, coins)) % MOD;
    return memo[x] = ans;
}

int bottom_up_way(int x, const vector<int>& coins) {
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        int res = 0;
        for (int coin : coins) {
            if (coin > i || dp[i - coin] == -1) continue;
            res = (res + dp[i - coin]) % MOD;
        }
        dp[i] = res;
    }
    return dp[x];
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

    vector<int> memo(x+1, -1);
    cout << top_down_way_memo(x, memo, coins) << '\n';
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

