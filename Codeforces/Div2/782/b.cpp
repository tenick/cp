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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    for(ll& i : arr) cin >> i;
    vector<ll> ps;
    for (ll i : arr)
        ps.push_back(ps.empty() ? i : ps.back() + i);
    
    ll currLoc = 0;
    ll currCost = 0;
    ll ans = b*ps.back();
    for (int i = 0; i < n; i++) {
        ll nextLoc = arr[i];
        ll conquerCost = b * (nextLoc - currLoc); 
        // cout << "conquering cost = " << conquerCost << '\n';
        currCost += conquerCost;
        if (i < n-1) {
            ll moveCost = a * (nextLoc - currLoc); 
            // cout << "moving cost = " << moveCost << '\n';
            currCost += moveCost;
            currLoc = nextLoc;
        }
        // cout << "current accumulated cost = " << currCost << '\n';
        // cout << "new location = " << currLoc << '\n';
        ll conquerRemainingCost = b * ((ps.back() - ps[i]) - currLoc * (n - i - 1));
        // cout << "conquering remaining cost = " << conquerRemainingCost << '\n';
        ll currans = currCost + conquerRemainingCost;
        // cout << "curr ans = " << currans << '\n';
        // cout << '\n';
        ans = min(ans, currans);
    }
    
    cout << ans << '\n';
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