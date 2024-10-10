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

set<ull> possible;
void solve(){
    ll n; cin >> n;
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    if (possible.find(n) != possible.end()) {
        cout << "YES\n";
        return;
    }
    ll c = n - 1ll;
    ull indet = 1ull + 4ull * c;
    ll det = sqrt(indet);
    if (det * det != indet) {
        cout << "NO\n";
        return;
    }
    ll detl = det;
    if ((1ll - detl) % 2 == 0) {
        
        if (abs(1ll - detl) / 2 <= 1) cout << "NO\n";
        else cout << "YES\n";
    }
    else cout << "NO\n";
}

int upperbound(ll val, ll base) {
    return floor(log(val)/log(base));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision
    const ll limit = 1e18;
    for (ll k = 2; k <= 1000000; k++) {
        ull curr = k*k;
        ull currsum = 1ull + 1*k + 1*curr;
        possible.insert(currsum);
        int iter = 0;
        for (int j = 3; j <= upperbound(limit, k); j++) {
            curr *= k;
            currsum += curr;
            possible.insert(currsum);
            iter++;
        }
        //cout << "max for " << i << " is " << currsum << " at " << iter << " iterations\n";
    }
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}