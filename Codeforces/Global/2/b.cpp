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
    int n, h;
    cin >> n >> h;
    vector<int> milks(n);
    for (int& i : milks) cin >> i;
    int ans = 0;
    multiset<int, greater<int>> ms;
    for (int i = 0; i < n; i++) {
        int currh = h;
        ms.insert(milks[i]);
        bool possible = true;
        int prev = -1;
        int j = 0;
        for (int milk : ms) {
            if (j == 0) {
                prev = milk;
                j++;
            }
            else {
                if (max(prev, milk) <= currh) {
                    currh -= max(prev, milk);
                    j = 0;
                    prev = -1;
                }
                else {
                    possible = false;
                    break;
                }
            }
        }
        if (prev > currh)
            possible = false;
        if (!possible)
            break;
        ans++;
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}