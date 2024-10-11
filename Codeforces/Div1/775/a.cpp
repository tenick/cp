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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> colorByXInds(100000);
    vector<vector<int>> colorByYInds(100000);
    vector<ll> colorXSum(100000);
    vector<ll> colorYSum(100000);
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            grid[i].push_back(val-1);
            colorByYInds[val-1].push_back(i);
            colorXSum[val-1] += j;
            colorYSum[val-1] += i;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            colorByXInds[grid[j][i]].push_back(i);
        }
    }

    ll ans = 0;
    for (int i = 0; i < 100000; i++) {
        if (colorByXInds[i].empty())
            continue;
        
        ll xsum = colorXSum[i];
        for (int j = 0; j < colorByXInds[i].size(); j++) {
            ans += xsum - (colorByXInds[i].size() - j) * colorByXInds[i][j];
            xsum -= colorByXInds[i][j];
        }

        ll ysum = colorYSum[i];
        for (int j = 0; j < colorByYInds[i].size(); j++) {
            ans += ysum - (colorByYInds[i].size() - j) * colorByYInds[i][j];
            ysum -= colorByYInds[i][j];
        }
    }
    cout << ans << '\n';
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