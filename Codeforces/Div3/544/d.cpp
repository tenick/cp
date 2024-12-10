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

#define ONLINE_JUDGE

void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  vector<int> b(n);
  for (int& i : b) cin >> i;
  int ans = 0;
  map<pair<bool, pair<int, int>>, int> mp;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ans += b[i] == 0;
      continue;
    }
    if (b[i] == 0) {
      pair<bool, pair<int, int>> tofind{false,{0,0}};
      if (mp.find(tofind) == mp.end())
        mp[tofind] = 0;
      mp[tofind]++;
      continue;
    }
    int gcf = gcd(abs(a[i]), abs(b[i]));
    bool neg = !((a[i] < 0) ^ (b[i] < 0));
    pair<bool, pair<int, int>> tofind{neg, {abs(a[i]/gcf), abs(b[i]/gcf)}};
    if (mp.find(tofind) == mp.end())
      mp[tofind] = 0;
    mp[tofind]++;
  }
  int maxcnt = 0;
  for (auto& kvp : mp){
    maxcnt = max(maxcnt, kvp.second);
  }
  cout << ans + maxcnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
}

