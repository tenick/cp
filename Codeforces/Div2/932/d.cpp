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
    int n, c;
    cin >> n >> c;
    vector<int> s(n);
    for (int& i : s) cin >> i;
    vector<int> oddPs(n,0);
    for (int i = n-1; i >= 0; i--) {
        int prev = i == n-1 ? 0 : oddPs[i+1];
        oddPs[i] = prev + (s[i] % 2 == 1);
    }
    vector<int> evenPs(n,0);
    for (int i = n-1; i >= 0; i--) {
        int prev = i == n-1 ? 0 : evenPs[i+1];
        evenPs[i] = prev + (s[i] % 2 == 0);
    }

    ll cnt = 1ll*(c+1)*(c+2)/2;
    for (int i = 0; i < n; i++){
        int val = s[i];
        ll xpyCnt = val / 2 + 1;
        ll ymxCnt = c - val;
        int ymxDups = 0;
        if (val % 2 == 0)
            ymxDups = i == n-1 ? 0 : evenPs[i+1];
        else ymxDups = i == n-1 ? 0 : oddPs[i+1];
        cnt -= (xpyCnt + (ymxCnt - ymxDups));
    }
    cout << cnt << '\n';
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