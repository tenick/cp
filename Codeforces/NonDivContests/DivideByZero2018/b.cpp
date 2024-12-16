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

bool good(int hi, int ops, vector<ll>& c) {
  for (int i = 0; i < c.size(); i++) {
    ll need = c[i] - hi;
    if (need <= 0) continue;
    if (need > ops) return false;
    ops -= need;
  }
  return true;
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n, k1, k2;
  cin >> n >> k1 >> k2;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  vector<int> b(n);
  for (int& i : b) cin >> i;

  vector<ll> c;
  for (int i = 0; i < n; i++) {
    c.push_back(abs(b[i] - a[i]));
  }
  sort(c.begin(), c.end());
  ll lo=0, hi=1e9, ub=-1, ops=k1+k2;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (good(mid, ops, c)) {
      ub = mid;
      hi = mid -1;
    }
    else lo = mid + 1;
  }

  ll ans = 0;
  if (ub > 0) {
    ll ubcnt = 0;
    for (ll i : c) {
      if (i < ub) {
        ans += 1ll * i * i;
        continue;
      }
      ops -= i - ub;
      ubcnt++;
    }
    ans += 1ll * ub * ub * (ubcnt - ops);
    ans += 1ll * (ub-1) * (ub-1) * ops;
  }
  else {
    ll sum = accumulate(c.begin(), c.end(), 0ll);
    ops -= sum;
    ans = ops % 2;
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

