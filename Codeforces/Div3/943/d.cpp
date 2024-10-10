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
    ll n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<ll> perm(n);
    vector<ll> a(n);
    for (ll& i : perm) cin >> i;
    for (ll& i : a) cin >> i;

    ll bmax = 0, bcurr = 0;
    ll smax = 0, scurr = 0;
    int cnt = 0;
    while (k-- && cnt < n) {
        // cout << pb << " " << ps << " " << bcurr << " " << scurr << '\n';

        bcurr += a[pb-1];
        bmax = max(bmax, bcurr + 1ll * a[pb-1] * k);
        pb = perm[pb-1];

        scurr += a[ps-1];
        smax = max(smax, scurr + 1ll * a[ps-1] * k);
        ps = perm[ps-1];

        // cout << "--new = " << pb << " " << ps << " " << bcurr << " " << scurr << '\n';

        cnt++;
    }
    if (bmax == smax) cout << "Draw\n";
    else if (bmax > smax) cout <<"Bodya\n";
    else cout << "Sasha\n";
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