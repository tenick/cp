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

bool possible(int len, int k, int& ans , const vector<int>& segs) {
    int start = segs[0];
    int i = 0;
    int totallen = 0;
    while (i < segs.size()) {
        if (segs[i] - start + 1 <= len) {
            i++;
        }
        else {
            k--;
            if (k == 0) {
                ans = 1e9;
                return false;
            }
            totallen += segs[i-1] - start + 1;
            start = segs[i];
        }
    }
    totallen += segs[i-1] - start + 1;
    ans = totallen;
    return true;
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> segs(n);
    for (int& i : segs) cin >> i;
    int l = 1, r = 1e9, ans = 1e9;
    int currans;
    while (l < r) { // finding smallest possible tape across, using at most k tapes
        int mid = (l + r) / 2;
        if (possible(mid, k, currans, segs)) {
            r = mid-1;
            ans = min(ans, currans);
        }
        else l = mid + 1;
    }

    if (possible(r, k, currans, segs))
        ans = min(ans, currans);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}