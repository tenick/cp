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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    ll P = 0;
    ll M = 0;
    for (char c : s) {
        P += c == '+';
        M += c == '-';
    }
    ll D = P - M;
    while (q--) {
        ll q0, q1;
        cin >> q0 >> q1;
        if (D == 0) {
            cout << "YES\n";
            continue;
        }

        if (q0 == q1) {
            cout << "NO\n";
            continue;
        }

        if ((q1 * D) % (q0 - q1) != 0) {
            cout << "NO\n";
            continue;
        }

        ll k = (-q1 * D) / (q0 - q1);
        if (k >= -M && k <= P) cout << "YES\n";
        else cout << "NO\n";
    }
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