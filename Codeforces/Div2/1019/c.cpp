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

template <typename T> inline T iceil(T a, T b) {
    return (a + b - 1) / b;
}

#define MOD_ANSWER
#ifdef MOD_ANSWER
constexpr int MOD = 1e9 + 7;
#endif
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2){
            res *= a;
#ifdef MOD_ANSWER
            res %= MOD;
#endif
        } 
        a *= a;
#ifdef MOD_ANSWER
        a %= MOD;
#endif
        b /= 2;
    }
    return res;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    vector<int> lcntok(n);
    for (int i = 0; i < n; i++) {
        int prev = i == 0 ? 0 : lcntok[i-1];
        lcntok[i] = prev + (arr[i] <= k);
    }
    vector<int> rcntok(n);
    for (int i = n-1; i >= 0; i--) {
        int prev = i == n-1 ? 0 : rcntok[i+1];
        rcntok[i] = prev + (arr[i] <= k);
    }
    //for (int i = 0; i < n; i++)
        //cout << lcntok[i] << ' ';
    //cout << '\n';
    //for (int i = 0; i < n; i++)
        //cout << rcntok[i] << ' ';
    //cout << '\n';
    for (int i = 1; i < n-1; i++) {
        if (arr[i] <= k) {
            int lcnt = lcntok[i-1];
            bool lprevbad = arr[i-1] > k && i > 1;
            int lcntb = i - lcnt - lprevbad;
            //cout << "lcnt = " << lcnt << " lcntbad = " << lcntb << '\n';
            if (lcnt >= lcntb) {
                cout << "YES\n";
                return;
            }

            int rcnt = rcntok[i+1];
            bool rprevbad = arr[i+1] > k && i < n-2;
            int rcntb = n - i - 1 - rcnt - rprevbad;
            //cout << "rcnt = " << rcnt << " rcntbad = " << rcntb << '\n';
            if (rcnt >= rcntb) {
                cout << "YES\n";
                return;
            }
        }
        else {
            int l = i, r = i;
            while (r+1 < n-1 && arr[r+1] > k)
                r++;
            
            int lcnt = lcntok[l-1];
            int lcntb = l - lcnt;
            int rcnt = rcntok[r+1];
            int rcntb = n - r - 1 - rcnt;
            if (lcnt >= lcntb && rcnt >= rcntb) {
                cout << "YES\n";
                return;
            }

            i = r;
        }
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

