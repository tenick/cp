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
    ll n, x;
    cin >> n >> x;
    ll cnt = 0;
    for (ll a = min(n/2, x); a >= 1; a--) {
        for (ll b = min(min((n - a) / (a + 1), a), x-a); b >= 1; b--) {
            ll c = min(min((n - a * b) / (a + b), b), x - a - b);
            if (c <= 0) 
                continue;

            if (a == b) {
                if (a == 1) {
                    cnt++;
                }
                else {
                    ll mult = c;
                    ll toAdd = 0;
                    if (b == c) {
                        toAdd++;
                        mult--;
                    }
                    toAdd += 3ll * mult;
                    cnt += toAdd;
                }
            }
            else {
                ll toAdd = 0;
                ll mult = c;
                if (b == c) {
                    toAdd += 3;
                    mult--;
                }
                toAdd += 6ll * mult;
                cnt += toAdd;
            }
            // cout << "(" << a << ", " << b << ", " << c << ")\n";
        }
    }
    cout << cnt << '\n';
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