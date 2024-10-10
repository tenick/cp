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

    int streak1 = 0;
    int curr = a[0];
    for (int i : a){
        if (i == curr) streak1++;
        else break;
    }
    int streak2 = 0;
    int curr2 = a[n-1];
    for (int i = n-1; i >= 0; i--){
        if (curr2 == a[i]) streak2++;
        else break;
    }
    if (curr == curr2) {
        if (streak1 == n) {
            cout << 0 << '\n';
            return;
        }
        streak1 += streak2;
        cout << n - streak1 << '\n';
    }
    else {
        cout << n - max(streak1, streak2) << '\n';
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