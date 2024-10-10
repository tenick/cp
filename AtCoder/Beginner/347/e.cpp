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
    int n, q;
    cin >> n >> q;
    
    ll sum = 0;
    vector<int> seen(n, -1);
    vector<ll> ps;
    vector<ll> ans(n, 0);
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;

        if (seen[x] == -1){
            cnt++;
            seen[x] = i;
        }
        else {
            cnt--;
            ll prev = seen[x] == 0 ? 0 : ps[seen[x]-1];
            ans[x] += sum - prev;
            seen[x] = -1;
        }

        sum += cnt;
        ps.push_back(sum);
    }
    for (int i = 0; i < n; i++){
        int ind = seen[i];
        if (ind == -1) continue;

        ll prev = ind == 0 ? 0 : ps[ind-1];
        ans[i] += sum - prev;
    }
    for (int i : ans) cout << i << ' ';
    cout << '\n';
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