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
            // we can always reach 0 by just picking any of the button, then keep pressing that all throughout n rounds
            cout << "YES\n";
            continue;
        }
        // from here on, D != 0

        // let 0 <= k1 <= P (k1 = the no. of times q0 was pressed on +)
        // let 0 <= k2 <= M (k2 = the no. of times q0 was pressed on -)

        // q[0]k1 + q[1](P-k1) - q[0]k2 - q[1](M-k2) = 0
        // q[0]k1 - q[0]k2 + q[1](P-k1) - q[1](M-k2) = 0
        // q[0](k1-k2) + q[1](P-k1-M+k2) = 0
        // q[0](k1-k2) + q[1](D-(k1-k2)) = 0

        // let k = k1-k2
        // q[0]k + q[1](D-k) = 0
        // q[0]k + q[1]D - q[1]k = 0
        // q[0]k - q[1]k + q[1]D = 0
        // (q[0] - q[1])k + q[1]D = 0
        // (q[0] - q[1])k = -q[1]D
        if (q0 == q1) {
            // then LHS = 0 and RHS != 0 (because D != 0 AND 1 <= q0, q1 <= 10^9)
            // so it's impossible to win if q0 == q1
            cout << "NO\n";
            continue;
        }

        // from here on, q0 != q1
        // k = -q[1]D / (q[0] - q[1])
        if ((q1 * D) % (q0 - q1) != 0) {
            // k must be an integer, since k = k1 - k2 (where k1 and k2 are integers)
            // in this case, it's not, then it's impossible
            cout << "NO\n";
            continue;
        }

        ll k = (-q1 * D) / (q0 - q1);
        // finally, what values of k are valid?
        // again:
        // k = k1 - k2
        // 0 <= k1 <= P
        // 0 <= k2 <= M

        // if k is positive, then: 
        // k1 > k2 
        // k2 = k1-k
        // k1 >= k 

        // from our earlier constraint, k1 <= P
        // so k <= k1 <= P
        // or k <= P (by transitivity) 
        // i.e. k must be at most P

        // if k is negative, then:
        // k2 > k1
        // k1 = k + k2
        // k2 >= -k

        // from our earlier constraint, k2 <= M
        // so, k < 0 < -k <= k2 <= M
        // (multiply all inequalities by -1)
        // -k > 0 > k >= -k2 >= -M

        // or k >= -M (by transitivity) 
        // i.e. k must be at least -M

        // so possible k's would be in the range [-M, P]
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