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

ll maxsubarr(int l, int r, const vector<ll>& arr) {
    l = max(0, l);
    r = min((int)arr.size()-1, r);
    ll maxsum = 0, currsum = 0;
    for (int i = l; i <= r; i++) {
        if (currsum + arr[i] < 0) {
            currsum = 0;
        }
        else currsum += arr[i];
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}

#define ONLINE_JUDGE
void solve(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> arr(n);
    for (ll& i : arr) cin >> i;

    vector<int> zeroInds;
    for (int i = 0; i < n; i++)
        if (s[i] == '0') zeroInds.push_back(i);

    // first check if impossible already or there's already maxsubarr == k
    // by checking if the subarrays between 2 adjacent zeros have a maximum sub-array > k
    // if found a subarr with already maxsubarr == k, just set all pos at 0 a big negative number
    // (you can't do anything to lower that)
    if (zeroInds.size() == 0) {
        ll maxsum = maxsubarr(0, n-1, arr);
        if (maxsum == k) {
            cout << "YES\n";
            for (ll i : arr) cout << i << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
        return;
    }
    else {
        bool found = false;
        for (int i = 0; i < zeroInds.size(); i++) {
            int l = (i == 0 ? 0 : zeroInds[i-1]+1), r = zeroInds[i]-1;
            ll maxsum = maxsubarr(l, r, arr);
            if (maxsum > k) {
                cout << "NO\n";
                return;
            }
            if (maxsum == k) found = true;
        }
        int l = zeroInds.back()+1, r = n-1;
        ll maxsum = maxsubarr(l, r, arr);
        if (maxsum > k) {
            cout << "NO\n";
            return;
        }
        if (maxsum == k) found = true;
        if (found) {
            cout << "YES\n";
            for (int i = 0; i < arr.size(); i++) {
                if (s[i] == '0')
                    cout << ((ll)-1e18) << ' ';
                else cout << arr[i] << ' ';
            }
            cout << '\n';
            return;
        }
    }
    
    // from here on, you can always find an answer
    cout << "YES\n";

    // just pick any index i with a s[i] == 0, and replace it with an integer 'val' such that it gives max subarray sum == k 
    // if there's multiple i's, any i is possible, but i just pick the first smallest i

    // to find the 'val':
    // keep iterating back from i-1, until you reach start/zero index, keep track of max sum
    ll maxsuml = 0, currsum = 0; // since im already at 0, i don't need to do anything
    for (int j = zeroInds[0] - 1; j >= 0; j--) {
        currsum += arr[j];
        maxsuml = max(maxsuml, currsum);
    }
    // keep iterating forward from i+1, until you reach end/zero index, keep track of max sum
    ll maxsumr = 0;
    currsum = 0;
    for (int j = zeroInds[0] + 1; j <= min(n-1, (zeroInds.size() == 1 ? n-1 : zeroInds[1]-1)); j++) {
        currsum += arr[j];
        maxsumr = max(maxsumr, currsum);
    }
    ll val = k - maxsuml - maxsumr;
    for (int z = 0; z < arr.size(); z++) {
        if (s[z] == '0') {
            if (z == zeroInds[0])
                cout << val << ' ';
            else
                cout << (ll)-1e18 << ' ';
        }
        else cout << arr[z] << ' ';
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

