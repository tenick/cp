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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll& i : arr) cin >> i;
    unordered_map<ll, ll> remCnt;
    bool allZero = true;
    for (ll i : arr) {
        if (i % k == 0)
            continue;
        allZero &= i % k == 0;
        if (remCnt.find(i % k) == remCnt.end())
            remCnt[i % k] = 0;
        remCnt[i % k]++;
    }
    if (allZero) {
        cout << 0 << '\n';
        return;
    }
    ll largestRem = 0;
    ll largestRemCnt = 0;
    for (auto& kvp : remCnt) {
        if (kvp.second >= largestRemCnt) {
            if (kvp.second > largestRemCnt) {
                largestRem = kvp.first;
                largestRemCnt = kvp.second;
            }
            if (kvp.second == largestRemCnt && kvp.first < largestRem) {
                largestRem = kvp.first;
            }
        }
    }
    cout << 1ll + k * (largestRemCnt - 1) + k - largestRem << '\n';
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