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
constexpr ll MOD = 998244353;
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

ll rcway(ll i, ll evenRemain, ll n, vector<vector<ll>>& memo, const vector<ll>& arr) {
    if (evenRemain == 0)
        return 1;
    if (i == arr.size() || arr[i] == 0)
        return 0;
    if (memo[i][evenRemain] != -1)
        return memo[i][evenRemain];

    ll cnt = arr[i];
    ll combs = 0;
    ll currans = 1;
    // can take?
    if (evenRemain >= cnt) {
        combs += nCk(evenRemain, cnt);
        currans = rcway(i+1, evenRemain - cnt, n, memo, arr);
    }

    // can skip?
    ll oddRemain = n - evenRemain;
    if (oddRemain >= cnt) {
        combs += nCk(oddRemain, cnt);
        currans = (currans * rcway(i+1, evenRemain, n, memo, arr)) % MOD;
    }

    cout << "i = " << i << " even remain = " << evenRemain << '\n';
    cout << "combs = " << combs << " currans = " << currans << '\n';
    return memo[i][evenRemain] = (combs * currans) % MOD;
}


#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    vector<ll> arr(26);

    for (ll& i : arr) cin >> i;
    sort(arr.rbegin(), arr.rend());

    ll n = 0;
    for (ll i : arr) n += i;

    vector<vector<ll>> memo(26, vector<ll>(n+1, -1));

    cout << rcway(0, n/2, n, memo, arr) << '\n';

    for (auto& row : memo) {
        for (ll j : row)
            cout << j << ' ';
        cout << '\n';
    }
    return;

    ll evens = n / 2;
    ll odds = n / 2;
    if (n % 2 == 1) odds++;

    
    ll ans = 1;
    for (ll& cnt : arr) {
        if (cnt == 0) break;
        ll ce = nCk(evens, cnt);
        ll co = nCk(odds, cnt);
        cout << "remain size = " << n << '\n';
        cout << "curr cnt = " << cnt << '\n';
        cout << "evens = " << evens << '\n';
        cout << "odds = " << odds << '\n';
        cout << "ce = " << ce << " | co = " << co << '\n';
        ll interm = ((co + ce) * ans);
        if (interm > MOD) interm %= MOD;
        if (interm != 0)
            ans = interm;
        if (interm == 0) {
            ll uhh = nCk(n, cnt);
            interm = (uhh * ans) % MOD;
            ans = interm;
        }
        cout << "interm = " << interm << '\n';
        n -= cnt;
        evens = n / 2;
        odds = n / 2;
        if (n % 2 == 1) odds++;

        cout << "curr ans is = " << ans << "\n\n";
    }
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

    //cout << nCk(8, 3) << '\n'; // 56
    //cout << nCk(10, 2) << '\n'; // 45
    //cout << nCk(5, 3) << '\n'; // 10
    //cout << nCk(1, 1) << '\n'; // 1
    //cout << '\n';

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}


