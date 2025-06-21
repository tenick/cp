#include <climits>
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
    ll n, s, x;
    cin >> n >> s >> x;

    vector<ll> arr(n);
    for (ll& i : arr) cin >> i;

    // map<currSum, <numGTX, xCnt, LTXCntSegs, xCntSegs>
    map<ll, tuple<ll, int, int, int>> mp; 
    ll currSum = 0, ans = 0;
    int numGTX = 0, xCnt = 0;
    for (ll& num : arr) {
        currSum += num;
        numGTX += num > x;
        xCnt += num == x;

        ll toFind = s - currSum;
        if (mp.find(toFind) == mp.end())
            mp[toFind] = {-1, -1, 0, 0};
        auto& [tNumGTX, tXCnt, tLTXCntSegs, tXCntSegs] = mp[-toFind];
        if (tNumGTX != numGTX) {
            tNumGTX = numGTX;
            tXCnt = xCnt;
            tLTXCntSegs = 0;
            tXCntSegs = 0;
        }
        else {
            if (tXCnt != xCnt) {
                tXCnt = xCnt;
                tLTXCntSegs += tXCntSegs;
                tXCntSegs = 0;
            }
            ans += tLTXCntSegs;
        }

        // check if curr segment is good by itself
        if (numGTX == 0 && xCnt > 0 && currSum == s)
            ans++;

        // update mp by adding current segment into it
        auto& [t2NumGTX, t2XCnt, t2LTXCntSegs, t2XCntSegs] = mp[currSum];
        if (mp.find(currSum) == mp.end())
            mp[currSum] = {-1, -1, 0, 0};
        if (t2NumGTX != numGTX) {
            t2NumGTX = numGTX;
            t2XCnt = xCnt;
            t2LTXCntSegs = 0;
            t2XCntSegs = 1;
        }
        else {
            if (t2XCnt != xCnt) {
                t2XCnt = xCnt;
                t2LTXCntSegs += t2XCntSegs;
                t2XCntSegs = 0;
            }
            t2XCntSegs++;
        }
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

