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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int& i : nums) cin >> i;
    if (n == 1) {
        cout << nums[0] << '\n';
        return;
    }
    auto cmp = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first < b.first; };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < n-1; i++) {
        pq.push({nums[i+1] - nums[i], {i, i+1}});
    }
    for (int i = n-1; i > 0; i--) {
        pq.push({nums[i-1] - nums[i], {i, i-1}});
    }

    while (k-- && !pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int fromi = top.second.first;
        int toi = top.second.second;
        if (nums[toi] - nums[fromi] != top.first) {
            k++;
            continue;
        }
        int result = nums[toi] - top.first;
        if (result >= nums[toi]) continue;

        nums[toi] -= top.first;
        if (fromi < toi && toi < n-1)
            pq.push({nums[toi+1] - nums[toi], {toi, toi+1}});
        if (fromi > toi && toi > 0)
            pq.push({nums[toi-1] - nums[toi], {toi, toi-1}});
    }
    ll sum = 0;
    for (int i : nums)
        sum += i;
    cout << sum << '\n';
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