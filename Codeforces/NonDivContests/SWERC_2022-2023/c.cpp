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

template<typename C> //0 = search right, 1 = search left, 2 = found!!!!! 
int possible(ll c, ll P, ll M, ll q0, ll q1, C comp) {
    if (q1 < 0 && abs(c*q1) > M)
        return 1;
    if (q1 > 0 && c*q1 > P)
        return 1;
    
    ll mult = 1;
    if (q1 > 0) mult = -1;

    ll lhs = mult * (P-M-c*q1);
    ll rhs = c*q0;
    // cout << "raw = " << (P - M - c*q1) << " mult = " << mult << " c = " << c << " lhs=" << lhs << " rhs=" << rhs << '\n';
    if (comp(lhs, rhs))
        return 0;
    else if (lhs == rhs)
        return 2;
    return 1;
}

template<typename C>
bool binarysearch(ll P, ll M, ll q0, ll q1, C comp1) {
    ll l = 1, r = 1e9;
    // cout << "binary searching q0=" << q0 << " q1=" << q1 << " P=" << P << " M=" << M << '\n';
    while (l <= r) {
        ll mid = (l + r) / 2;
        int res = possible(mid, P, M, q0, q1, comp1);
        if (res == 0) {
            l = mid + 1;
        }
        else if (res == 1) {
            r = mid - 1;
        }
        else {
            return true;
        }
        // cout << "new l = " << l << " new r = " << r << "\n";
    }
    return false;
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
    while (q--) {
        ll q0, q1;
        cin >> q0 >> q1;
        // make it lowest form
        ll qgcd = gcd(q0, q1);
        q0 = q0/qgcd;
        q1 = q1/qgcd;
        
        if (P == M)
            cout << "YES\n";
        else {
            if (q0 == q1) {
                if (P == M)
                    cout << "YES\n";
                else cout << "NO\n";
            }
            else if (q0 > q1) {
                if (binarysearch(P, M, q0, q1, greater<ll>()) ||
                    binarysearch(P, M, q0, -q1, greater<ll>()))
                    cout << "YES\n";
                else cout << "NO\n";
            }
            else {
                if (binarysearch(P, M, q0, q1, less<ll>()) ||
                    binarysearch(P, M, q0, -q1, less<ll>()))
                    cout << "YES\n";
                else cout << "NO\n";
            }
        }
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