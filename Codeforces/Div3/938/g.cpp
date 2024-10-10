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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (auto& row : grid)
        for (int& i : row) cin >> i;
    
    vector<vector<set<int>>> dp(n, vector<set<int>>(m, set<int>()));
    dp[0][0].insert(grid[0][0]);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (i < n-1){
                set<int> toAdd;
                for (int k : dp[i][j]) {
                    toAdd.insert(gcd(k, grid[i+1][j]));
                }
                for (int k : toAdd) {
                    dp[i+1][j].insert(k);
                }
            }
            if (j < m-1){
                vector<int> toAdd;
                for (int k : dp[i][j]) {
                    toAdd.push_back(gcd(k, grid[i][j+1]));
                }
                for (int k : toAdd) {
                    dp[i][j+1].insert(k);
                }
            }
        }
    }
    int ans = 1;
    // for (auto& row : dp) {
    //     for (auto& vals : row) {
    //         for (int i : vals) cout << i << ' ';
    //         cout << " | ";
    //     }
    //     cout << '\n';
    // }
    for (int val : dp[n-1][m-1]){
        ans = max(ans, val);
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