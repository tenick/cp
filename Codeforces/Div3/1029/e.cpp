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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> b(n);
    for (int& i : b) cin >> i;

    vector<map<int, pair<bool, bool>>> numByInds(n, map<int, pair<bool, bool>>());
    for (int i = 0; i < n; i++) {
        int aval = a[i]-1;
        if (numByInds[aval].find(i) == numByInds[aval].end()) {
            numByInds[aval][i] = {false, false};
        }
        numByInds[aval][i].first = true;

        int bval = b[i]-1;
        if (numByInds[bval].find(i) == numByInds[bval].end()) {
            numByInds[bval][i] = {false, false};
        }
        numByInds[bval][i].second = true;
    }

    int ans = 0;
    for (auto& mp : numByInds) {
        if (mp.empty())
            continue;
        auto last = *mp.rbegin();
        bool done = false;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            auto kvp = *it;
            switch (last.first - kvp.first) {
                case 0:
                    if (last.second.first && last.second.second) {
                        done = true;
                        ans = max(ans, last.first + 1);
                    }
                    break;
                case 1:
                    if ((last.second.first && kvp.second.first) || 
                        (last.second.second && kvp.second.second) ||
                        (kvp.second.first && kvp.second.second)) {
                        done = true;
                        ans = max(ans, kvp.first + 1);
                    }
                    break;
                default:
                    done = true;
                    ans = max(ans, kvp.first + 1);
                    break;
            }
            if (done) 
                break;
        }
    }
    cout << ans << '\n';
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

