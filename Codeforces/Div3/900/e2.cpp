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

bool possible(int l, int r, int k, const vector<vector<int>>& precomp) {
    int val = 0;
    for (int i = 0; i < 30; i++)
        if (precomp[r][i] - (l == 0 ? 0 : precomp[l-1][i]) == r - l + 1)
            val += (1 << i);
    return val >= k;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr)
        cin >> i;
    int q;
    cin >> q;
    vector<vector<int>> precomp(n, vector<int>(30));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            precomp[i][j] = bit_check(arr[i], j);
            if (i > 0) 
                precomp[i][j] += precomp[i-1][j];
        }
    }
    while (q--) {
        int lo, k;
        cin >> lo >> k;
        lo--;
        int l = lo, r = n-1;
        int ans = -1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (possible(lo, mid, k, precomp)) {
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }
        if (possible(lo, l, k, precomp))
            ans = l;
        cout << (ans == -1 ? -1 : ans+1) << ' ';
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