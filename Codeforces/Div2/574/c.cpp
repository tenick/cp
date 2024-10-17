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

ll rc(int i, bool isPrevRow2, vector<vector<ll>>& memo, const vector<vector<int>>& heights) {
    if (i >= memo[isPrevRow2].size())
        return 0;
    if (memo[isPrevRow2][i] != -1)
        return memo[isPrevRow2][i];
    // take
    ll ans = heights[!isPrevRow2][i] + rc(i+1, !isPrevRow2, memo, heights);

    // skip
    ll ans2 = rc(i+1, isPrevRow2, memo, heights);

    return memo[isPrevRow2][i] = max(ans, ans2);
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> heights(2, vector<int>(n));
    for (int& i : heights[0]) cin >> i;
    for (int& i : heights[1]) cin >> i;
    vector<vector<ll>> memo(2, vector<ll>(n, -1));
    rc(0, false, memo, heights);
    rc(0, true, memo, heights);
    cout << max(memo[0][0], memo[1][0]) << '\n';
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