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

template <typename T> bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline T bit_toggle(T number, int pos) {
    return number ^ ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline T bit_set(T number, int pos) {
    return number | ((T)1 << pos);
}

ll rcWay(int i, int k, bool fromDir, vector<int>& nums, vector<vector<vector<int>>>& memo) {
    if (k == 0) return 0;
    if (i < 0 || i >= nums.size()) return 0;
    if (memo[i][k-1][fromDir] != -1) return memo[i][k-1][fromDir];

    ll removed = 0;
    if (fromDir) { // from right
        removed = nums[i] - nums[i+1];

        int temp = nums[i]; 
        nums[i] = nums[i+1];
        ll bestRemove = LLONG_MIN;
        for (int j = 0; j < nums.size(); j++) {
            bestRemove = max(bestRemove, max(rcWay(j-1, k-1, true, nums, memo), rcWay(j+1, k-1, false, nums, memo)));
        }
        nums[i] = temp;
        removed += bestRemove;
    }
    else { // from left
        removed = nums[i] - nums[i-1];

        int temp = nums[i]; 
        nums[i] = nums[i-1];
        ll bestRemove = LLONG_MIN;
        for (int j = 0; j < nums.size(); j++) {
            bestRemove = max(bestRemove, max(rcWay(j-1, k-1, true, nums, memo), rcWay(j+1, k-1, false, nums, memo)));
        }
        nums[i] = temp;
        removed += bestRemove;
    }
    return memo[i][k-1][fromDir] = removed;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    vector<vector<vector<int>>> memo(nums.size(), vector<vector<int>>(k, vector<int>(2, -1)));
    ll canRemove = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        canRemove = max(canRemove, max(rcWay(i-1, k, true, nums, memo), rcWay(i+1, k, false, nums, memo)));
    }
    ll sum = 0;
    for (int i : nums) sum += i;
    cout << sum - canRemove << '\n';
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