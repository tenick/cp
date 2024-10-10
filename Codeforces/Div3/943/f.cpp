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
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;
    
    vector<int> xors;
    int currxor = 0;
    set<pair<int, int>> xorst;
    for (int i = 0; i < n; i++) {
        currxor ^= nums[i];
        xorst.insert({currxor, i});
        xors.push_back(currxor);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        int prev = l == 1 ? 0 : xors[l-2];
        int rangeXor = xors[r-1] ^ prev;
        if (rangeXor == 0) {
            cout << "YES\n";
        }
        else {
            int toFind = xors[r-1];
            auto first = xorst.lower_bound({toFind, l-1});
            if (first == xorst.end()) {
                cout << "NO\n";
                continue;
            }
            auto last = xorst.lower_bound({prev, r});
            last--;
            if ((*first).second < (*last).second && (*last).second != r - 1) {
                cout << "YES\n";
                continue;
            }
            else cout << "NO\n";
        }
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
