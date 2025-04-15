#include <iostream>
#include <climits>
#include <vector>
 
using namespace std;
 
int dpway(int x) {
    vector<int> dp(x+1, 0);
    for (int i = 1; i <= x; i++) {
        int cx = i, ans = INT_MAX;
        while (cx != 0) {
            int c = cx % 10;
            if (c != 0)
                ans = min(ans, dp[i - c] + 1);
            cx /= 10;
        }
        dp[i] = ans;
    }
    return dp[x];
}
 
int rcmemoway(int x, vector<int>& memo) {
    if (x == 0)
        return 0;
    if (memo[x] != -1)
        return memo[x];
    int cx = x, ans = INT_MAX;
    while (cx != 0) {
        int c = cx % 10;
        if (c != 0)
            ans = min(ans, rcmemoway(x - c, memo) + 1);
        cx /= 10;
    }
    return memo[x] = ans;
}
 
int rcway(int x) {
    if (x == 0)
        return 0;
    int cx = x, ans = INT_MAX;
    while (cx != 0) {
        int c = cx % 10;
        if (c != 0)
            ans = min(ans, rcway(x - c) + 1);
        cx /= 10;
    }
    return ans;
}
 
int main() {
    int n;
    cin >> n;
    cout << dpway(n) << '\n';
    // vector<int> memo(n+1, -1);
    // cout << rcmemoway(n, memo) << '\n';
    // cout << rcway(n) << '\n';
    return 0;
}
