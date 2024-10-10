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

void calc(int i, vector<pair<int, int>>& dp, vector<int>& a, vector<bool>& visited){
    if (visited[i]) return;
    visited[i] = true;
    int prev = abs((i == 0 ? 2e9 : a[i-1]) - a[i]);
    int next = abs((i == a.size() - 1 ? 2e9 : a[i+1]) - a[i]);
    if (prev < next) {
        calc(i-1, dp, a, visited);
        if (dp[i-1].first == -1)
            dp[i] = {i-1, i};
        else dp[i] = {dp[i-1].first, i};
    }
    else {
        calc(i+1, dp, a, visited);
        if (dp[i+1].first == -1)
            dp[i] = {i, i+1};
        else dp[i] = {i, dp[i+1].second};
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<pair<int, int>> dp(n, {-1, -1});
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        calc(i, dp, a, visited);
    }
    for (auto kvp : dp){
        cout << kvp.first << ' ' << kvp.second << '\n';
    }
    int m;
    cin >> m;
    while (m--){
        int c1, c2;
        cin >> c1 >> c2;
        pair<int, int> covered = dp[c1-1];
        if (c1 < c2){
            if (c2 - 1 <= covered.second){
                cout << c2 - 1 - c1 + 1 << '\n';
            }
            else cout << covered.second - c1 + 1 + abs(a[c2-1] - a[covered.second]) << '\n';
        }
        else {
            if (c2 - 1 >= covered.first){
                cout << c1 - 1 - c2 + 1 << '\n';
            }
            else cout << c1 - 1 - covered.first + abs(a[c2-1] - a[covered.first]) << '\n';
        }
    }
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