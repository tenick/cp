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
    ll n, b, x;
    cin >> n >> b >> x;
    vector<ll> r(n);
    for (ll& i : r) cin >> i;
    sort(r.begin(), r.end());
    
    ll ans = 0;
    ll totalPairs = 0;
    for (int i = 0; i < n; i++){
        ll pairs = r[i] * (r[i] - 1) / 2;
        cout << "if k=" << r[i] << " pairs = " << pairs;
        totalPairs += pairs;
        cout << " | TOTAL: " << totalPairs;
        ll cost = (r[i] - 1) * x;
        cout << " | COST: " << cost << '\n';
        ans = max(ans, (totalPairs + n - i - 1) * b - cost);
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