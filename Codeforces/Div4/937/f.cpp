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
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 2;
    a--;
    if (a == -1) {
        cnt = 1;
        a++;
        b--;
    }
    if (b == -1)
        cnt = 0;
    if (cnt == 0) {
        if (c > 1) cout << -1 << '\n';
        else cout << 0 << '\n';
        return;
    }

    int ans = 0;
    while (cnt != 0){
        int newCnt = 0;

        int useda = min(cnt, a);
        a -= useda;
        cnt -= useda;
        newCnt += 2 * useda;

        int usedb = min(cnt, b);
        b -= usedb;
        cnt -= usedb;
        newCnt += usedb;

        int usedc = min(cnt, c);
        c -= usedc;
        cnt -= usedc;

        if (cnt != 0) {
            cout << -1 << '\n';
            return;
        }

        cnt = newCnt;
        ans++;
    }
    if (cnt != 0 || a != 0 || b != 0 || c != 0) {
        cout << -1 << '\n';
        return;
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