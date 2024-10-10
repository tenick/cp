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
    ll n, k, q;
    cin >> n >> k >> q;

    vector<ll> a(k);
    for (ll& i : a) cin >> i;
    vector<ll> b(k);
    for (ll& i : b) cin >> i;

    vector<pair<ll, ll>> queries;
    for (int i = 0; i < q; i++) {
        ll qi; cin >> qi;
        queries.push_back({qi, i});
    }
    sort(queries.begin(), queries.end());

    int i = 0;
    vector<ll> ans(q);
    for (auto& query : queries) {
        while (a[i] < query.first) {
            i++;
        }
        // calculate minute per unit of distance
        ll preva = i == 0 ? 0 : a[i-1];
        ll prevb = i == 0 ? 0 : b[i-1];
        long double mpd = (long double)(b[i] - prevb) / (a[i] - preva);
        ans[query.second] = prevb + floor(mpd * (query.first - preva));
    }
    for (ll i : ans) cout << i << ' ';
    cout << '\n';
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