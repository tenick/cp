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

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int& i : arr) cin >> i;
  sort(arr.begin(), arr.end());
  vector<pair<int, int>> numcnt;
  for (int i : arr) {
    if (numcnt.empty() || numcnt.back().first != i)
      numcnt.push_back({i, 0});
    numcnt.back().second++;
  }
  int l=0, r=0, ans=0, curr=0;
  while (r < numcnt.size()) {
    if (l != r && numcnt[r].first - numcnt[r-1].first != 1){
      curr = 0;
      l = r;
    }
    while(r - l + 1 > k) {
      curr -= numcnt[l].second;
      l++;
    }
    curr += numcnt[r].second;
    ans = max(ans, curr);
    r++;
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
