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

ll cntFind(int num, vector<int>& triples){
    int res = 0;
    int orig = num;
    int placeVal = 1;
    while (num != 0) {
        int curr = num % 10 * placeVal;
        for (int i = 1; i < 10; i++) {
            int val = i * placeVal;
            if (val == curr) continue;
            int toFind = orig - curr + val;
            res += triples[toFind];
        }
        num /= 10;
        placeVal *= 10;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;
    vector<int> triples(1000, 0);

    int curr = nums[0] * 100 + nums[1] * 10;
    ll ans = 0;
    for (int i = 2; i < n; i++) {
        curr += nums[i];
        ans += cntFind(curr, triples);
        triples[curr]++;
        curr -= nums[i-2] * 100;
        curr *= 10;
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