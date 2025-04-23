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

bool solvecase1(int n, int k, const vector<int>& arr) {
    vector<int> ps;
    for (int i = 0; i < n; i++) {
        int prev = i == 0 ? 0 : ps.back();
        int toAdd = arr[i] <= k ? 1 : -1;
        ps.push_back(prev + toAdd);
    }
    vector<int> msp(n, INT_MIN);
    for (int i = n-2; i >= 0; i--) {
        int prev = i == n-2 ? INT_MIN : msp[i+1];
        msp[i] = max(prev, ps[i]);
    }

    for (int i = 0; i < n - 2; i++) {
        if (ps[i] >= 0 && msp[i+1] >= ps[i])
            return true;
    }
    return false;
}

bool solvecase3(int n, int k, const vector<int>& arr) {
    int prev = 0, gi = n+1;
    for (int i = 0; i < n; i++) {
        int toAdd = arr[i] <= k ? 1 : -1;
        prev += toAdd;
        if (prev >= 0) {
            gi = i;
            break;
        }
    }

    prev = 0;
    int gj = -2;
    for (int i = n-1; i >= 0; i--) {
        int toAdd = arr[i] <= k ? 1 : -1;
        prev += toAdd;
        if (prev >= 0) {
            gj = i;
            break;
        }
    }
    
    return gj - gi >= 2;
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

    bool c3 = solvecase3(n, k, arr);
    bool c1 = solvecase1(n, k, arr);
    reverse(arr.begin(), arr.end());
    bool c2 = solvecase1(n, k, arr);

    if (c1 || c2 || c3)
        cout << "YES\n";
    else cout << "NO\n";
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

