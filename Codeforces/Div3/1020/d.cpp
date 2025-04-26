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
    vector<int> a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    if (n == 1) {
        if (a[0] >= b[0])
            cout << 0;
        else cout << b[0];
        cout << '\n';
        return;
    }

    vector<int> ps(n, 0);
    int l = 0;
    for (int i = 0; i < m; i++) {
        while (l < n && a[l] < b[i]) {
            ps[l] = l == 0 ? 0 : ps[l-1];
            l++;
        }
        if (l == n)
            break;
        ps[l] = 1 + (l == 0 ? 0 : ps[l-1]);
        l++;
    }
    while (l < n) {
        ps[l] = (l == 0 ? 0 : ps[l-1]);
        l++;
    }

    vector<int> ss(n, 0);
    int r = n-1;
    for (int i = m-1; i >= 0; i--) {
        while (r >= 0 && a[r] < b[i]) {
            ss[r] = r == n-1 ? 0 : ss[r+1];
            r--;
        }
        if (r < 0)
            break;
        ss[r] = 1 + (r == n-1 ? 0 : ss[r+1]);
        r--;
    }
    while (r >= 0) {
        ss[r] = (r == n-1 ? 0 : ss[r+1]);
        r--;
    }

    if (ps[n-1] == m || ss[0] == m) {
        cout << "0\n";
        return;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        if (ps[i] + ss[i+1] == m-1)
            ans = min(ans, b[ps[i]]);
    }
    if (ss[0] == m-1) ans = min(ans, b[0]);
    if (ps[n-1] == m-1) ans = min(ans, b[m-1]);

    if (ans == INT_MAX) {
        cout << -1 << "\n";
    }
    else cout << ans << '\n';
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

