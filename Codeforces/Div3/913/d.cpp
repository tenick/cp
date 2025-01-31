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

bool possible(ll k, const vector<pair<ll, ll>>& segs) {
    ll lo = 0, ro = 0;
    for (int i = 0; i < segs.size(); i++) {
        ll li = segs[i].first, ri = segs[i].second;
        // consider 5 intersection cases:
        // case 1: origin segment is inside next segment
        if (lo >= li && ro <= ri) {
            lo = max(lo - k, li);
            ro = min(ro + k, ri);
        }
        // case 2: next segment is inside origin segment
        else if (li >= lo && ri <= ro) {
            lo = li;
            ro = ri;
        }
        // case 3: origin segment is outside next segment
        else if (max(lo, li) > min(ro, ri)) {
            if (ro < li) {
                if (ro + k < li) 
                    return false;
                lo = li;
                ro = min(ro + k, ri); 
            }
            if (ri < lo) {
                if (ri < lo - k)
                    return false;
                lo = max(lo - k, li);
                ro = ri;
            }
        }
        // case 4: origin segment intersects left part of next segment
        else if (ro >= li && ro <= ri) {
            lo = li;
            ro = min(ro + k, ri);
        }
        // case 5: origin segment intersects right part of next segment
        else if (ri >= lo && ri <= ro) {
            lo = max(lo - k, li);
            ro = ri;
        }
    }
    return true;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> segs;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    ll l=0, r=1e9;
    while(l < r) {
        ll k = (l + r) / 2;
        if (possible(k, segs))
            r = k;
        else
            l = k + 1;
    }
    cout << r << '\n';
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