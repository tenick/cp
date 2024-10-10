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
    vector<vector<bool>> grid(7, vector<bool>(7, false));
    for (int i = 0; i < 7; i++){
        string s;
        cin >> s;
        for (int j = 0; j < 7; j++){
            if (s[j] == 'B')
                grid[i][j] = true;
        }
    }
    vector<vector<int>> dp(7, vector<int>(7, 0));
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 6; j++){
            if (!grid[i][j])
                continue;
            int cnt = 0;
            if (i > 0){
                if (grid[i-1][j+1]){
                    cnt++;
                    dp[i-1][j+1]++;
                }
            }
            if (i < 6){
                if (grid[i+1][j+1]){
                    cnt++;
                    dp[i+1][j+1]++;
                }
            }
            dp[i][j] += cnt;
        }
    }
    for (auto row : dp){
        for (int i : row) cout << i << ' ';
        cout << '\n';
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