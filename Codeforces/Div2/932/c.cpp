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

bool rcWay(int i, int took, int prevb, int maxTook, int curr, int l, vector<pair<int, int>>& msgs){
    if (took == maxTook){
        return curr <= l;
    }
    if (curr > l) return false;
    // take
    bool res1 = rcWay(i+1, took+1, msgs[i].second, maxTook, curr + msgs[i].first + (msgs[i].second - (prevb == - 1 ? msgs[i].second : prevb)), l, msgs);

    // skip
    bool res2 = rcWay(i+1, took, prevb, maxTook, curr, l, msgs);
    return res1 | res2;
}

void solve(){
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> msgs;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        msgs.push_back({a, b});
    }
    cout << "reach here?\n";
    bool found = false;
    for (auto& msg : msgs){
        cout << msg.first << " less?\n";
        if (msg.first <= l){
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "not found here2?\n";
        cout << 0 << '\n';
        return;
    }
    cout << "reach here2?\n";
    int lo=1, hi=n;
    int res = 1;
    while (lo < hi){
        int mid = (lo + hi) / 2;
        cout << mid << '\n';
        if (rcWay(0, 0, -1, mid, 0, l, msgs)){
            res = max(res, mid);
            lo = mid + 1;
        }
        else {
            res = mid - 1;
        }
    }
    if (rcWay(0, 0, -1, lo, 0, l, msgs)) res++;
    cout << res << '\n';
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