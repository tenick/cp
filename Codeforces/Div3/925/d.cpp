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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    int lcmxy = lcm(x, y);
    map<int, int> modFreq;
    for (int i : a){
        int val = i % lcmxy;
        if (modFreq.find(val) == modFreq.end()) modFreq[val] = 0;
        modFreq[val]++;
    }

    int ans = 0;
    for (auto& kvp : modFreq){
        int pair = abs(kvp.first - lcmxy);
        if (kvp.first * 2 % x == 0){
            ans += (kvp.second - 1) * kvp.second / 2;
        }
        if (kvp.first < lcmxy / 2 && abs(pair - kvp.first) >= y && modFreq.find(pair) != modFreq.end()){
            ans += kvp.second * modFreq[pair];
        }
        
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