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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll& i : arr) 
        cin >> i;
    if (arr[0] % 5 == 0) {
        for (ll& i : arr) {
            if (i % 5 != 0) {
                cout << "NO\n";
                return;
            }
            if (i % 10 == 5)
                i += 5;
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i-1]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }

    vector<ll> modflow{0, 2, 4, 6, 8, 0, 2, 4, 6, 8};
    for (ll& i : arr) {
        ll start = i % 10;
        if (start % 5 == 0) {
            cout << "NO\n";
            return;
        }
        while (start != 2) {
            i += start;
            start = modflow[start];
        }
    }

    ll maxelem = *max_element(begin(arr), end(arr));
    ll shouldBeDivisibleBy = 2 + 4 + 8 + 6;
    for (ll i : arr) {
        if ((maxelem - i) % shouldBeDivisibleBy != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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