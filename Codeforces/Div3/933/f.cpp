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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    for (int& i : p) cin >> i;

    map<int, int> freqp;
    int pi, pj;
    int prev = INT_MIN;
    for (int i = 0; i + 1 < n; i++){
        int val = p[i+1] - p[i];
        if (val > prev){
            pi = p[i];
            pj = p[i+1];
            prev = val;
        }
        if (freqp.find(val) == freqp.end()) freqp[val] = 0;
        freqp[val]++;
    }
    set<int> d;
    for (int i = 0; i < m; i++){
        int val;
        cin >> val;
        d.insert(val);
    }
    set<int> f;
    for (int i = 0; i < k; i++){
        int val;
        cin >> val;
        f.insert(val);
    }

    // for (auto& kvp : freqp) {
    //     cout << kvp.first << " " << kvp.second << '\n';
    // }

    if ((*std::prev(freqp.end(), 1)).second > 1) {
        cout << (*std::prev(freqp.end(), 1)).first<< '\n';
        return;
    }

    int a =(*std::prev(freqp.end(), 1)).first;
    int t = freqp.size() == 1 ? 0 : (*std::prev(freqp.end(), 2)).first;
    int mid = (pj - pi) / 2 + pi;
    int minAns = a;
    // cout << a << " | " << t << " | pi = " << pi << " pj = " << pj << '\n';
    // cout << "mid = " << mid << '\n';
    for (int model : d) {
        int toFind = max(mid - model, 1);
        // cout << "finding " << toFind << " for model=" << model << '\n';
        auto iter = f.lower_bound(toFind);
        bool preved = false;
        if (iter == f.end()) {
            preved = true;
            iter--;
        }
        int val1 = *iter;
        int p1 = val1 + model;
        // cout << "p1 = " << p1 << '\n';
        if (p1 > pi && p1 < pj) {
            minAns = min(minAns, max(abs(pi - p1), abs(pj - p1)));
        }
        if (iter != f.begin() && !preved) {
            iter--;
            int val2 = *iter;
            int p2 = val2 + model;
            // cout << "p2 = " << p2 << '\n';
            if (p2 > pi && p2 < pj) {
                minAns = min(minAns, max(abs(pi - p2), abs(pj - p2)));
            }
        }
    }
    cout << max(t, minAns) << '\n';
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