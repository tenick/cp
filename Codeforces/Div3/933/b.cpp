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

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a) cin >> i;
    int l = 0, r = n-1;
    while (l <= r) {
        while (l < n && a[l] == 0) l++;
        while (r >= 0 && a[r] == 0) r--;
        if (l+1 >= r) {
            break;
        }

        if (l+2 >= n) break;
        a[l+1] -= a[l] * 2;
        a[l+2] -= a[l];
        a[l] = 0;
        if (a[l] < 0 || a[l+1] < 0 || a[l+2] < 0){
            cout << "NO\n";
            return;
        }

        if (r-2 < 0) break;
        a[r-1] -= a[r] * 2;
        a[r-2] -= a[r];
        a[r] = 0;
        if (a[r] < 0 || a[r-1] < 0 || a[r-2] < 0){
            cout << "NO\n";
            return;
        }
    }
    for (ll i : a) {
        if (i != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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