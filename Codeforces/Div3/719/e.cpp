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

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> ps;
    vector<ll> pcnt;
    for (char c : s) {
        ll prevCnt = pcnt.empty() ? 0 : pcnt.back();
        ll prevs = ps.empty() ? 0 : ps.back();
        if (c == '*') {
            prevCnt++;
        }
        else {
            prevs += prevCnt;
        }
        ps.push_back(prevs);
        pcnt.push_back(prevCnt);
    }
    vector<ll> ss;
    vector<ll> scnt;
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        ll prevCnt = scnt.empty() ? 0 : scnt.back();
        ll prevs = ss.empty() ? 0 : ss.back();
        if (c == '*') {
            prevCnt++;
        }
        else {
            prevs += prevCnt;
        }
        ss.push_back(prevs);
        scnt.push_back(prevCnt);
    }
    reverse(ss.begin(), end(ss));
    reverse(scnt.begin(), end(scnt));

    ll ans = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, ps[i] + ss[i+1]);
    }
    if (ans == LLONG_MAX) ans = 0;
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