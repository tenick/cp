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

map<int, int> getSegs(vector<int>& arr){
  map<int, int> segByCnt;
  int cnt = 0;
  for (int i : arr) {
    if (i == 1) cnt++;
    else if (cnt > 0) {
      if (segByCnt.find(cnt) == segByCnt.end())
        segByCnt[cnt] = 0;
      segByCnt[cnt]++;
      cnt = 0;
    }
  }
  if (cnt > 0) {
    if (segByCnt.find(cnt) == segByCnt.end())
      segByCnt[cnt] = 0;
    segByCnt[cnt]++;
  }
  return segByCnt;
}

ll cntRects(ll r, ll c, map<int, int>& rowsegs, map<int, int>& colsegs) {
    auto rsiter = rowsegs.lower_bound(r);
    auto csiter = colsegs.lower_bound(c);
    if (rsiter == rowsegs.end() || csiter == colsegs.end())
      return 0;

    ll rs = 0;
    for (; rsiter != rowsegs.end(); rsiter++) {
      auto rss = *rsiter;
      rs += (rss.first - r + 1) * rss.second;
    }
    
    ll cs = 0;
    for (; csiter != colsegs.end(); csiter++) {
      auto css = *csiter;
      cs += (css.first - c + 1) * css.second;
    }

    return rs * cs;
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  ll n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  vector<int> b(m);
  for (int& i : b) cin >> i;
  auto rowsegs = getSegs(a);
  auto colsegs = getSegs(b);
  ll ans = 0;
  for (ll r = 1; r*r <= k; r++) {
    if (k % r != 0) 
      continue;
    ll c = k / r;

    ans += cntRects(r, c, rowsegs, colsegs);
    if (r*r == k) 
      continue;
    ans += cntRects(c, r, rowsegs, colsegs);
  }

  cout << ans << '\n';
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

