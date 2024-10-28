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

ll rc(ll size, map<ll, vector<int>>& vals, map<ll, ll>& memo) {
    if (memo.find(size) != memo.end())
        return memo[size];
    ll ans = size;
    if (vals.find(size + 1) == vals.end())
        return memo[size] = ans;
    for (int incr : vals[size+1]) {
        ans = max(ans, rc(size + incr, vals, memo));
    }
    return memo[size] = ans;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (ll& i : arr)
        cin >> i;
    
    map<ll, vector<int>> vals;
    for (int i = 1; i < n; i++) {
        ll val = arr[i]+i+1;
        vals[val].push_back(i);
    }
    map<ll, ll> memo;
    rc(n, vals, memo);
    cout << memo[n] << '\n';
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