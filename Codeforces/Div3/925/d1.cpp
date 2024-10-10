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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    map<int, map<int, int>> mp;
    for (int i : a){
        int val = i % x;
        if (mp.find(val) == mp.end()) mp[val] = map<int, int>();
        int val2 = i % y;
        if (mp[val].find(val2) == mp[val].end()) mp[val][val2] = 0;
        mp[val][val2]++;
    }

    ll ans = 0;
    for (auto& kvp : mp){
        if (kvp.first > x / 2) break;
        int ai = kvp.first;
        int aj = (x - ai) % x;
        if (mp.find(aj) == mp.end()) continue;
        auto& mp2 = mp[aj];

        for (auto& kvp2 : kvp.second){
            int bi = kvp2.first;
            if (ai != aj) ans += 1ll * kvp2.second * mp2[bi];
            else ans += 1ll * kvp2.second * (kvp2.second - 1) / 2;
        }
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