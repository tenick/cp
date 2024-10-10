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
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (ll& i : arr) cin >> i;
    vector<ll>ps1{0};
    vector<ll>ps2{0};
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ps1.push_back(ps1.back());
            ps2.push_back(ps2.back() + arr[i]);
        }
        else {
            ps1.push_back(ps1.back() + arr[i]);
            ps2.push_back(ps2.back());
        }
    }
    set<ll> subs{0};
    for (int i = 1; i <= n; i++) {
        ll toFind = ps2[i] - ps1[i];
        if (subs.find(toFind) != subs.end()) {
            cout << "YES\n";
            return;
        }
        subs.insert(toFind);
    }
    cout << "NO\n";
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