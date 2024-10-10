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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ull> a(n);
    for (ull& i : a) cin >> i;
    sort(a.begin(), a.end());

    ull ans = a[0];
    if (k == 1)
        for (int i = 1; i < n; i++)
            ans = min(ans, a[i] - a[i-1]);
    else if (k == 2) {
        for (int i = 0; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ull curr = a[j] - a[i];
                auto lbIter = lower_bound(a.begin(), a.end(), curr);
                ans = min(ans, min(curr, *lbIter - curr));
                if (lbIter != a.begin())
                    ans = min(ans, curr - *(--lbIter));
            }
        }
    }
    else if (k >= 3)
        ans = 0;
    
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