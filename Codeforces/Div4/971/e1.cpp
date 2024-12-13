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

ll arsum(ll n) {
  return n * (n+1) / 2;
}
ll calcans(ll n, ll k, ll i) {
  ll sk = k * (k-1) / 2;
  ll s1 = arsum(k + i - 1);
  ll s2 = arsum(k + n - 1) - s1;
  s1 -= sk;
  return abs(s1 - s2);
}
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  ll n, k;
  cin >> n >> k;
  
  ll sk = k*(k-1) / 2;
  int l = 0, r = n, ans = -1;
  while (l < r) {
    int mid = (l+r) / 2;
    ll s1 = arsum(k + mid - 1);
    ll s2 = arsum(k + n - 1) - s1;
    s1 -= sk;
    if (s1 <= s2) {
      ans = mid;
      l = mid+1;
    }
    else {
      r = mid;
    }
  }
  cout << min(calcans(n, k, ans), calcans(n, k, ans+1)) << '\n';
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

