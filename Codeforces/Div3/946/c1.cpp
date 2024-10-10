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

void handleMp(pair<int, int> toIns, int neq, map<pair<int, int>, pair<map<int, int>, int>>& mp) {
    if (mp.find(toIns) == mp.end()) mp[toIns] = {map<int, int>(), 0};
    if (mp[toIns].first.find(neq) == mp[toIns].first.end()) mp[toIns].first[neq] = 0;
    mp[toIns].first[neq]++;
    mp[toIns].second++;
}

ll cntDiff(pair<int, int> toIns, int neq, map<pair<int, int>, pair<map<int, int>, int>>& mp) {
    ll res = 0;
    if (mp.find(toIns) != mp.end()) {
        res += mp[toIns].second;
        if (mp[toIns].first.find(neq) != mp[toIns].first.end())
            res -= mp[toIns].first[neq];
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;


    ll ans = 0;
    map<pair<int, int>, pair<map<int, int>, int>> mp1;
    map<pair<int, int>, pair<map<int, int>, int>> mp2;
    map<pair<int, int>, pair<map<int, int>, int>> mp3;
    for (int i = 2; i < n; i++) {
        pair<int, int> toIns1 = {nums[i-1], nums[i]};
        int neq1 = nums[i-2];
        pair<int, int> toIns2 = {nums[i-2], nums[i]};
        int neq2 = nums[i-1];
        pair<int, int> toIns3 = {nums[i-2], nums[i-1]};
        int neq3 = nums[i];

        ans += cntDiff(toIns1, neq1, mp1);
        ans += cntDiff(toIns2, neq2, mp2);
        ans += cntDiff(toIns3, neq3, mp3);

        handleMp(toIns1, neq1, mp1);
        handleMp(toIns2, neq2, mp2);
        handleMp(toIns3, neq3, mp3);
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