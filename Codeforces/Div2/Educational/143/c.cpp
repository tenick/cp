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
    vector<ll> teas(n);
    for (ll& i : teas) cin >> i;
    vector<ll> taster(n);
    for (ll& i : taster) cin >> i;
    
    vector<ll> tasterPS;
    for (int i = 0; i < n; i++) {
        ll currsum = i == 0 ? 0 : tasterPS.back();
        tasterPS.push_back(currsum + taster[i]);
    }

    vector<ll> updMult(n);
    vector<ll> updIncr(n);
    for (int i = 0; i < n; i++) {
        ll tea = teas[i];
        ll lbval = tea + (i == 0 ? 0 : tasterPS[i-1]);
        
        auto iter = lower_bound(tasterPS.begin()+i, tasterPS.end(), lbval);
        int iterIndex = iter - tasterPS.begin();
        if (iterIndex == i) { // taster can drink more than tea amount
            updIncr[i] += tea;
        } 
        else {
            updMult[i]++;
            if (iterIndex < n) {
                updMult[iterIndex]--;
                updIncr[iterIndex] += lbval - tasterPS[iterIndex-1];
            }
        }
    }
    ll currMult = 0;
    for (int i = 0; i < n; i++) {
        currMult += updMult[i];
        cout << taster[i] * currMult + updIncr[i] << ' ';
    }
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