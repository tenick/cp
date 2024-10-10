#include <iostream>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_a
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    vector<int> dp(n, 1001);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++){
        if (i + 1 < dp.size())
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        if (i + 2 < dp.size())
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }
    cout << dp[n - 1] << '\n';
}