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

const int MOD = 1e9+7;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(2, vector<ll>(n, 1));
    int currrow = 0;
    while(--k) {
        int opp = (currrow + 1) % 2;
        for (int i = 1; i <= n; i++) {
            ll sm = 0;
            for (int j = i; j <= n; j+=i)
                sm = (sm + dp[currrow][j-1]) % MOD;
            dp[opp][i-1] = sm;
        }
        currrow = opp;
    }
    ll ans = 0;
    for (ll i : dp[currrow]) ans = (ans + i) % MOD;
    cout << ans << '\n';
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