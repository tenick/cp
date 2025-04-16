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
constexpr int MOD = 998244353;
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

vector<ll> fact(500001, 0);
vector<ll> ifact(500001, 0);
ll nCk(ll n, ll k) {
    if (k > n) return 0;
    return (fact[n] * ((ifact[n - k] * ifact[k]) % MOD)) % MOD;
}


#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    vector<ll> freqs(26);

    for (ll& i : freqs) cin >> i;

    ll n = 0;
    for (ll i : freqs) n += i;

    ll evenc = n / 2, oddc = iceil(n, 2ll);

    vector<ll> dp(evenc+1, 0);
    dp[0] = 1;
    for (ll freq : freqs) {
        if (freq == 0) continue;
        for (ll x = evenc; x >= freq; x--) {
            dp[x] = (dp[x] + dp[x - freq]) % MOD;
        }
    }

    // calculate the constant 
    ll combs = (fact[evenc] * fact[oddc]) % MOD;
    for (ll freq : freqs)
        combs = (combs * ifact[freq]) % MOD;

    ll ans = (dp[evenc] * combs) % MOD;

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    // precomp factorials, inverse mods
    fact[0] = 1;
    for (int i = 1; i <= 500000; i++) {
        fact[i] = (i * fact[i-1]) % MOD;
    }

    ifact[500000] = binpow(fact[500000], MOD-2); 
    for (int i = 499999; i >= 0; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
    }

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}

