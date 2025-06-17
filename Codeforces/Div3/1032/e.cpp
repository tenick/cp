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

    int a, b;
    cin >> a >> b;
    vector<int> l;
    while (a != 0) {
        l.push_back(a % 10);
        a /= 10;
    }
    reverse(l.begin(), l.end());

    vector<int> r;
    while (b != 0) {
        r.push_back(b % 10);
        b /= 10;
    }
    reverse(r.begin(), r.end());

    int n = l.size();
    int diffAt = -1, bad = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] != r[i]) {
            diffAt = i;
            break;
        }
        bad += 2;
    }
    if (diffAt == -1) {
        cout << bad << '\n';
        return;
    }
    if (r[diffAt] - l[diffAt] > 1) {
        cout << bad << '\n';
        return;
    }

    // l focused
    int lbad = 0;
    for (int i = diffAt+1; i < n; i++) {
        int opts = 9 - l[i];
        if (r[i] > l[i]) opts--;
        if (opts <= 0) lbad++;
        else break;
        if (l[i] != 9) break;
        if (r[i] == 9) lbad++;
    }

    // r focused
    int rbad = 0;
    for (int i = diffAt+1; i < n; i++) {
        int opts = r[i];
        if (r[i] > l[i]) opts--;
        if (opts <= 0) rbad++;
        else break;
        if (r[i] != 0) break;
        if (l[i] == 0) rbad++;
    }

    cout << bad + 1 + min(lbad, rbad) << '\n';
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

