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

// use pos = 0, if you want to work with 1st bit of given number
template <typename T> inline bool bit_check(T number, int pos) {
    return (number >> pos) & (T)1;
}
template <typename T> inline void bit_toggle(T& number, int pos) {
    number ^= ((T)1 << pos);
}
template <typename T> inline T bit_clear(T number, int pos) {
    return number & ~((T)1 << pos);
}
template <typename T> inline void bit_set(T& number, int pos) {
    number |= ((T)1 << pos);
}

void solve(){
  int n;
  cin >> n;
  vector<int> weights(n);
  for (int& i : weights) cin >> i;
  vector<int> nodesByNeighborCnt(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    nodesByNeighborCnt[u-1]++;
    nodesByNeighborCnt[v-1]++;
  }
  ll curr = 0;
  vector<ll> ans(n-1);
  multiset<pair<int, int>> ms;
  for (int i = 0; i < n; i++) {
    curr += 1ll * nodesByNeighborCnt[i] * weights[i];
    if (nodesByNeighborCnt[i] > 1) ms.insert({weights[i], nodesByNeighborCnt[i]});
  }
  ans[n-2] = curr;
  for (int i = 0; i < n-2; i++) {
    auto loIter = ms.begin();
    auto lo = *loIter;
    ms.erase(loIter);
    curr -= lo.first;
    lo.second--;
    ans[n-2-i-1] = curr;
    if (lo.second == 1) continue;
    ms.insert(lo);
  }
  for (ll i : ans) cout << i << ' ';
  cout << '\n';
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
