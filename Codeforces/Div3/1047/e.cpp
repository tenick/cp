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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    map<int, int> freq;
    for (int i : arr) freq[i]++;

    // perform 1 op
    int hole = 0;
    for (auto& kvp : freq) {
        if (hole != kvp.first) break;
        hole++;
    }
    map<int, int> freq1;
    for (auto& kvp : freq) {
        if (kvp.second == 1 && kvp.first < hole)
            freq1[kvp.first] = 1;
        else freq1[hole] += kvp.second;
    }
    k--;
    if (k == 0) {
        ll ans1 = 0;
        for (auto& kvp : freq1)
            ans1 += (ll)kvp.first * kvp.second;
        cout << ans1 << '\n';
        return;
    }

    // perform 2 op
    hole = 0;
    for (auto& kvp : freq1) {
        if (hole != kvp.first) break;
        hole++;
    }
    map<int, int> freq2;
    for (auto& kvp : freq1) {
        if (kvp.second == 1 && kvp.first < hole)
            freq2[kvp.first] = 1;
        else freq2[hole] += kvp.second;
    }
    k--;
    if (k == 0) {
        ll ans1 = 0;
        for (auto& kvp : freq2)
            ans1 += (ll)kvp.first * kvp.second;
        cout << ans1 << '\n';
        return;
    }

    // check if good (will never change)
    bool good = true;
    for (auto& kvp : freq2) {
        if (kvp.second != 1) {
            good = false;
            break;
        }
    }
    if (good) {
        ll ans3 = 0;
        for (auto& kvp : freq2) {
            ans3 += kvp.first;
        }
        cout << ans3 << '\n';
        return;
    }

    ll res = 0;
    if (freq2.rbegin()->first == freq2.size()) {
        ll last = freq2.rbegin()->first;
        ll log = last;
        if (k % 2 == 1) last--;
        for (auto& kvp : freq2) {
            if (kvp.first == log) res += last * kvp.second;
            else res += (ll)kvp.first * kvp.second;
        }

    }
    else {
        ll last = freq2.rbegin()->first;
        ll log = last;
        if (k % 2 == 1) last++;
        ll ans = 0;
        for (auto& kvp : freq2) {
            if (kvp.first == log) res += last * kvp.second;
            else res += (ll)kvp.first * kvp.second;
        }
    }

    cout << res << '\n';
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

