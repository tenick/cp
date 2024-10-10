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
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<ll> ps;
    ps.push_back(0);
    for (int i = 0; i < n - 1; i++) {
        int prev = abs((i == 0 ? 2e9 : a[i-1]) - a[i]);
        int next = abs(a[i+1] - a[i]);
        ll val = ps.back();
        if (prev < next)
            val += abs(a[i] - a[i+1]);
        else val++;
        ps.push_back(val);
    }
    vector<ll> ss;
    ss.push_back(0);
    for (int i = n-1; i > 0; i--) {
        int prev = abs((i == n-1 ? 2e9 : a[i+1]) - a[i]);
        int next = abs(a[i-1] - a[i]);
        ll val = ss.back();
        if (prev < next)
            val += abs(a[i] - a[i-1]);
        else val++;
        ss.push_back(val);
    }
    reverse(ss.begin(), ss.end());
    int m;
    cin >> m;
    while (m--){
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 < c2) cout << ps[c2-1] - ps[c1-1] << '\n';
        else cout << ss[c2-1] - ss[c1-1] << '\n';
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