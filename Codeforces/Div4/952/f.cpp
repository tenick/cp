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

template <typename T> bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline T bit_toggle(T number, int pos) {
    return number ^ ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline T bit_set(T number, int pos) {
    return number | ((T)1 << pos);
}

// void checkPq(priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq, vector<int>& atts) {
//     cout << "curr state:\n";
//     while (!pq.empty()) {
//         auto curr = pq.top();
//         int turn = curr.first;
//         int use = curr.second.first;
//         int index = curr.second.second;
//         cout << turn << " | " << use << " | " << index << " | attack = " << atts[index] << '\n';

//     }
// }
void solve(){
    ll h, n;
    cin >> h >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> c(n);
    for (int& i : c) cin >> i;

    auto cmp = [](pair<ll, int> a, pair<ll, int> b) { return a.first > b.first; };
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < n; i++) {
        pq.push({1 + c[i], i});
        h -= a[i];
    }
    if (h <= 0) {
        cout << 1 << '\n';
        return;
    }

    ll turnsAns = 1;
    while (h > 0) {
        auto curr = pq.top();
        pq.pop();
        ll turn = curr.first;
        int index = curr.second;
        h -= a[index];
        pq.push({turn + c[index], index});
        turnsAns = turn;
    }
    cout << turnsAns << '\n';
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