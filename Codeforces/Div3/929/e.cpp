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

ll calc(ll m, ll u){
    return m * u - (m * (m - 1) / 2);
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int q;
    cin >> q;
    vector<int> ps;
    int curr = 0;
    for (int i : a){
        curr += i;
        ps.push_back(curr);
    }
    while (q--){
        int l, u;
        cin >> l >> u;
        int m = (2 * u + 1) / 2;
        int prev = l == 1 ? 0 : ps[l-2];
        int find = m + prev;
        auto iter = lower_bound(ps.begin(), ps.end(), find);
        if (iter == ps.end()) iter--;
        if (iter - ps.begin() <= l - 1){
            cout << l << ' ';
            continue;
        }
        int m1 = *iter;
        ll m1val = calc(m1 - prev, u);
        int ind1 = iter - ps.begin();

        if (iter != ps.begin() && iter - ps.begin() > l - 1){
            iter--;
            int m2 = *iter;
            int ind2 = iter - ps.begin();
            ll m2val = calc(m2 - prev, u);
            if (m2val >= m1val) ind1 = ind2;
        }
        cout << ind1 + 1 << ' ';
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