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
    sort(a.begin(), a.end());
    int cnt1 = 0;
    for (int i : a) cnt1 += i == 1;
    if (cnt1 != 0){
        if (cnt1 > 1) cout << "NO\n";
        else cout << "YES\n";
        return;
    }
    else {
        int sm = a[0];
        int smcnt = 0;
        for (int i : a){
            if (i == sm) smcnt++;
            if (i % sm != 0 && i % sm < sm) {
                cout << "YES\n"; 
                return;
            }
        }
        if (smcnt == 1) cout << "YES\n";
        else cout << "NO\n";
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