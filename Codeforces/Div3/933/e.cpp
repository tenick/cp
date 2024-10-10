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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<ll> costs;
    for (int i = 0; i < n; i++){
        multiset<ll> ms;
        ms.insert(1);
        vector<ll> dp{1};
        for (int j = 0; j < m; j++){
            int cost;
            cin >> cost;
            if (j == 0) continue;
            if (j - d - 2 >= 0) ms.erase(ms.find(dp[j-d-2]));
            dp.push_back(*ms.begin() + cost + 1);
            ms.insert(dp.back());
        }
        costs.push_back(dp.back());
    }
    int l = 0, r = k - 1;
    ll curr = 0;
    for (int i = 0; i <= r; i++) curr += costs[i];
    ll ans = curr;
    while (r < n-1){
        curr -= costs[l++];
        curr += costs[++r];
        ans = min(ans, curr);
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