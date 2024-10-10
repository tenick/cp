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
    ll n, k;
    cin >> n >> k;
    vector<ll> ships(n);
    for (ll& i : ships) cin >> i;

    int l=0, r=n-1;
    while (k > 0 && l <= r){
        if (l == r){
            ships[l] = max(0ll, ships[l] - k);
            break;
        }
        int minattack = min(ships[l], ships[r]);
        if (minattack*2 > k) {
            minattack = k / 2;
            ships[l] -= minattack + (k % 2 == 1);
            ships[r] -= minattack;

            break;
        }
        ships[l] -= minattack;
        ships[r] -= minattack;
        if (ships[l] == 0)
            l++;
        if (ships[r] == 0)
            r--;
        k -= minattack*2;
    }
    int sunk = 0;
    for (int i : ships)
        sunk += i == 0;
    cout << sunk << '\n';
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