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

template <typename T> inline T iceil(T a, T b) {
  return (a + b - 1) / b;
}

#define MOD_ANSWER
#ifdef MOD_ANSWER
constexpr int MOD = 1e9 + 7;
#endif
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b % 2){
      res *= a;
      #ifdef MOD_ANSWER
      res %= MOD;
      #endif
    } 
    a *= a;
    #ifdef MOD_ANSWER
    a %= MOD;
    #endif
    b /= 2;
  }
  return res;
}

#define ONLINE_JUDGE

void showms(multiset<int>& ms, const string& lbl) {
  cout << lbl << ": ";
  for (int i : ms) {
    cout << i << ' ';
  }
  cout << '\n';
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  cin >> n;
  vector<set<int>> nodesByNeighbors(n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    nodesByNeighbors[u-1].insert(v-1);
    nodesByNeighbors[v-1].insert(u-1);
  }

  multiset<int> degs;
  for (int i = 0; i < n; i++) {
    degs.insert(nodesByNeighbors[i].size());
  }
  // showms(degs, "curr ms");
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // cout << "at node " << (i+1) << "\n";
    multiset<int> tofix;
    int n1 = nodesByNeighbors[i].size();
    degs.erase(degs.find(n1));
    for (int nbr : nodesByNeighbors[i]) {
      int sz = nodesByNeighbors[nbr].size();
      degs.erase(degs.find(sz));
      degs.insert(sz-1);
      tofix.insert(sz-1);
    }
    // showms(degs, "after remove");
    int n2 = *degs.rbegin();
    ans = max(ans, 1 + n1 + n2 - 2);
    for (int nb2 : tofix) {
      degs.erase(degs.find(nb2));
      degs.insert(nb2+1);
    }
    degs.insert(n1);
    // showms(degs, "after fix");
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

