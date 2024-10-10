#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
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
    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    vector<int> dp(n);
    dp[n-1] = 1;
    for (int i = n - 2; i >= 0; i--){
        int val = nums[i];
        if (i + val < n){
            int nextval = i + val + 1 == n ? 0 : dp[i + val + 1];

            dp[i] = min(dp[i+1] + 1, nextval);
        }
        else {
            dp[i] = dp[i+1] + 1;
        }
    }

    cout << dp[0] << '\n';
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