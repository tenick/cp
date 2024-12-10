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

  ll n, k;
  cin >> n >> k;

  ll curr = 1, powc = 0;
  while (curr < k){
    powc++;
    curr *= 2;
  }
  if (n-1 < powc) {
    cout << -1 << '\n';
    return;
  }

  ll bits = k-1;
  int l=0, r=n-1;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (i+1 == n) {
      ans[l++] = i+1;
      break;
    }
    if (n - i - 2 < 50) {
      if (bit_check(bits, n-i-2)){
        ans[r--] = (i+1);
      }
      else ans[l++] = i+1;
    }
    else ans[l++] = i+1;
  }
  for (int i : ans) cout << i << ' ';
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

