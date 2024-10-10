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
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    // check first if beautiful
    bool same = true;
    for (int i : arr) same &= i == arr[0];
    if (same) {
        cout << -1 << '\n'; 
        return;
    }

    // reaching here means arr is beautiful
    // not figure out how many to remove
    int minLen = 1e9;
    int curr = -1;
    for (int i = 1; i < n-1; i++) {
        if (arr[i] != arr[0]) {
            minLen = min(minLen, i - curr - 1);
            curr = i;
        }
    }
    minLen = min(minLen, n - 1 - curr);
    cout << minLen << '\n';
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