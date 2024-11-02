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

// revisit 1
int rcWay(int i, const vector<int>& arr, vector<int>& memo) {
    if (i >= arr.size())
        return 0;
    if (memo[i] != -1)
        return memo[i];
    
    // skip
    int skip = 1 + rcWay(i+1, arr, memo);
    // take
    if (i + arr[i] + 1 <= arr.size()) { // can take
        int take = rcWay(i + arr[i] + 1, arr, memo);
        if (take < skip)
            skip = take;
    }
    return memo[i] = skip;
}

void recursiveMemoWay(int n, const vector<int>& arr) {
    vector<int> memo(n, -1);
    cout << rcWay(0, arr, memo) << '\n';
}

void bottomUpWay(int n, const vector<int>& arr) {
    vector<int> dp(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        int ans = dp[i+1] + 1;
        if (i + arr[i] + 1 < dp.size())
            ans = min(ans, dp[i+arr[i]+1]);
        dp[i] = ans;
    }
    cout << dp[0] << '\n';
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& i : arr) cin >> i;
    bottomUpWay(n, arr);
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