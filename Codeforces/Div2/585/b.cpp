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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    vector<int> dp(1, 0);
    int ind = 0;
    for (int i : arr) {
        dp[ind]++;
        if (i < 0) {
            ind++;
            dp.push_back(0);
        }
    }
    vector<int> dpps(dp.size(), 0);
    for (int i = 0; i < dp.size(); i+=2) {
        if (i - 2 >= 0) {
            dpps[i] = dp[i] + dpps[i-2];
        }
        else dpps[i] = dp[i];
    }
    for (int i = 1; i < dp.size(); i+=2) {
        if (i - 2 >= 0) {
            dpps[i] = dp[i] + dpps[i-2];
        }
        else dpps[i] = dp[i];
    }
    ll negs = 0;
    for (int i = 0; i < dp.size() - 1; i++) {
        ll curr = dpps[i];
        ll next = dp[i+1];
        if (i+1 == dp.size() - 1)
            next++;
        negs += curr * next;
    }
    ll pos = (ll)n * (n + 1) / 2 - negs;
    cout << negs << " " << pos << '\n';
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