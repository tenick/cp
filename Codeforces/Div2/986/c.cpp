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
    ll n, m, v;
    cin >> n >> m >> v;
    vector<ll> sects(n);
    for (ll& i : sects) cin >> i;
    
    vector<ll> ps;
    for (ll i : sects) {
        ps.push_back(ps.empty() ? i : ps.back() + i);
    }

    // get forward pieces
    vector<pair<ll, ll>> fPieces;
    ll l = 0, r = 0;
    ll sum = 0;
    while (r < n) {
        sum += sects[r];
        if (sum >= v) {
            fPieces.push_back({l, r});
            r++;
            l = r;
            sum = 0;
            if (fPieces.size() == m)
                break;
        }
        else r++;
    }
    if (fPieces.size() != m) {
        cout << -1 << '\n';
        return;
    }

    // get backward pieces
    vector<pair<ll, ll>> bPieces;
    l = n-1; r = n-1;
    sum = 0;
    while (l >= 0) {
        sum += sects[l];
        if (sum >= v) {
            bPieces.push_back({l, r});
            l--;
            r = l;
            sum = 0;
            if (bPieces.size() == m)
                break;
        }
        else l--;
    }

    // calculate alice max tastiness
    ll maxTasty = 0;
    pair<ll, ll> currBSeg {n, n};
    for (int i = m-1; i >= 0; i--) {
        ll fsegInd = fPieces[i].second;
        ll bsegInd = currBSeg.first - 1 < 0 ? 0 : currBSeg.first - 1;
        ll tastiness = ps[bsegInd] - ps[fsegInd];
        maxTasty = max(maxTasty, tastiness);
        currBSeg = bPieces[m - i - 1];
    }

    if (currBSeg.first - 1 >= 0) {
        maxTasty = max(maxTasty, ps[currBSeg.first - 1]);
    }


    cout << maxTasty << '\n';
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