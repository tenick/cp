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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> b(n);
    for (int& i : b) cin >> i;

    vector<pair<int, int>> moves;
    for (int i = 0; i < n; i++) {
        // odd top
        // find in bottom first, then swap if found
        int val = i*2 + 1;
        for (int j = 0; j < n; j++) {
            if (b[j] == val) {
                if (j < i) {
                    moves.push_back({2, j+1});
                    swap(b[j], b[j+1]);
                    j++;
                }
                moves.push_back({3, j+1});
                swap(a[j], b[j]);
                break;
            }
        }
        for (int j = n-1; j > i; j--) {
            if (a[j] != val) continue;
            moves.push_back({1, j});
            swap(a[j], a[j-1]);
        }

        // even bottom
        // find in top first, then swap if found
        val = (i+1)*2;
        for (int j = 0; j < n; j++) {
            if (a[j] == val) {
                if (j < i) {
                    moves.push_back({1, j+1});
                    swap(a[j], a[j+1]);
                    j++;
                }
                moves.push_back({3, j+1});
                swap(a[j], b[j]);
                break;
            }
        }
        for (int j = n-1; j > i; j--) {
            if (b[j] != val) continue;
            moves.push_back({2, j});
            swap(b[j], b[j-1]);
        }
    }

    cout << moves.size() << '\n';
    for (auto& move : moves) {
        cout << move.first << " " << move.second << '\n';
    }
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

