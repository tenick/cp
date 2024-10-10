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

template <typename T> bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline T bit_toggle(T number, int pos) {
    return number ^ ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline T bit_set(T number, int pos) {
    return number | ((T)1 << pos);
}

void solve(){
    int n;
    cin >> n;
    vector<int> perm(n);
    for (int& i : perm) cin >> i;
    set<pair<int, int>> evenInds;
    for (int i = 0; i < n; i+=2)
        evenInds.insert({perm[i], i});
    set<pair<int, int>> oddInds;
    for (int i = 1; i < n; i+=2)
        oddInds.insert({perm[i], i});
 
    set<pair<int, int>>& highs = (oddInds.lower_bound({n, 0}) == oddInds.end()) ? evenInds : oddInds;
    set<pair<int, int>>& lows = (oddInds.lower_bound({n, 0}) == oddInds.end()) ? oddInds : evenInds;

    vector<int> ans(n);
    int start = n;
    for (auto& kvp : highs) {
        ans[kvp.second] = start;
        start--;
    }
    for (auto& kvp : lows) {
        ans[kvp.second] = start;
        start--;
    }
    for (int i : ans) cout << i << ' ';
    cout << '\n';
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