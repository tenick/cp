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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    int div = gcd(a, b);
    int ans = INT_MAX;
    vector<int> rem;
    for (int i = 0; i < n; i++) {
        rem.push_back(arr[i] % div);
    }
    sort(rem.begin(), rem.end());
    int prev = -1;
    for (int i = 0; i < rem.size(); i++) {
        int curr = rem[i];
        if (prev == curr) continue;

        if (i == 0) {
            ans = min(ans, rem.back() - curr);
        }
        else ans = min(ans, prev + div - curr);
        prev = curr;
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