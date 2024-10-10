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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    
    set<int> changesAt{1};
    int curr = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] != curr)
            changesAt.insert(i+1);
        curr = arr[i];
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        auto lchange = changesAt.lower_bound(l);
        if (lchange == changesAt.end()) {
            cout << "-1 -1\n";
            continue;
        }
        if ((*lchange) == l) {
            lchange++;
            if (lchange == changesAt.end() || (*lchange) > r)
                cout << "-1 -1\n";
            else
                cout << l << " " << (*lchange) << '\n';
        }
        else if ((*lchange) <= r) {
            cout << l << " " << (*lchange) << '\n';
        }
        else cout << "-1 -1\n";
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