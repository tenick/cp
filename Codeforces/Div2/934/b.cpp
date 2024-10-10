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
    int n, k;
    cin >> n >> k;
    vector<int> seq(2*n);
    for (int& i : seq) cin >> i;
    map<int, pair<int, int>> possible;
    int l=0, r=1;
    int px = seq[0];
    while (r < 2 * k - 1){
        px ^= seq[r++];
    }
    for (int i = r; i < n; i++) {
        px ^= seq[i];
        if (possible.find(px) == possible.end()) possible[px] = {l, i};
        px ^= seq[l++];
    }
    l=n;
    r=n+1;
    px = seq[n];
    while (r < n + 2 * k - 1){
        px ^= seq[r++];
    }
    for (int i = r; i < 2 * n; i++) {
        px ^= seq[i];
        if (possible.find(px) != possible.end()){
            auto subseq = possible[px];
            for (int j = subseq.first; j <= subseq.second; j++){
                cout << seq[j] << ' ';
            }
            cout << '\n';
            for (int j = l; j <= i; j++){
                cout << seq[j] << ' ';
            }
            cout << '\n';
            return;
        }
        px ^= seq[l++];
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