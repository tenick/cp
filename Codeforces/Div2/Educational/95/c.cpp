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

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr) {
        cin >> i;
    }

    vector<vector<int>> dp(4, vector<int>(n, -1));
    dp[0][0] = arr[0];
    for (int i = 1; i < n; i++) {
        // for n2
        if (dp[2][i-1] != -1 || dp[3][i-1] != -1) {
            if (dp[2][i-1] != -1 && dp[3][i-1] != -1) {
                dp[0][i] = arr[i] + min(dp[2][i-1], dp[3][i-1]);
            }
            else if (dp[2][i-1] != -1)
                dp[0][i] = arr[i] + dp[2][i-1];
            else
                dp[0][i] = arr[i] + dp[3][i-1];
        }
        // for n1
        if (dp[0][i-1] != -1)
            dp[1][i] = arr[i] + dp[0][i-1];
        // for g2
        if (dp[0][i-1] != -1 || dp[1][i-1] != -1) {
            if (dp[0][i-1] != -1 && dp[1][i-1] != -1) {
                dp[2][i] = min(dp[0][i-1], dp[1][i-1]);
            }
            else if (dp[0][i-1] != -1)
                dp[2][i] = dp[0][i-1];
            else
                dp[2][i] = dp[1][i-1];
        }
        // for g1
        if (dp[2][i-1] != -1)
            dp[3][i] = dp[2][i-1];
    }
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int ans = n;
    for (int i = 0; i < 4; i++) {
        if (dp[i][n-1] == -1) continue;
        ans = min(ans, dp[i][n-1]);
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
