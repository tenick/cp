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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  int i = 0;
  while (i < k) {
    int hops = 1 + (n - i - 1) / k;
    // cout << "hops = " << hops << '\n';
    vector<int> acnts(26, 0);
    int maxcnt = 0;
    int j = i;
    while (j < k) {
      int h2 = 1 + (n - j - 1) / k;
      if (h2 != hops) break;

      j++;
    }
    int subn = j - i;
    int iter = 0, end = i + (subn / 2) + (subn % 2 == 1);
    // cout << "boutta cover " << subn << " chars from " << i << " with char = " << s[i] << "\n";
    for (; i < end; i++) {
      vector<int> acnts(26, 0);
      int maxcnt = 0, totalCnt = hops;
      // cout << "at i = " << s[i] << ": ";

      for (int m = 0; m < hops; m++) {
        // cout << s[i+m*k] << ' ';
        acnts[s[i+m*k]-'a']++;
        maxcnt = max(maxcnt, acnts[s[i+m*k]-'a']);
      }
      // cout << '\n';

      int backi = j - iter - 1;
      // cout << "backi = " << s[backi] << ": "; 
      if (backi != i) {
        totalCnt += hops;
        for (int m = 0; m < hops; m++) {
          // cout << s[backi+m*k] << ' ';
          acnts[s[backi+m*k]-'a']++;
          maxcnt = max(maxcnt, acnts[s[backi+m*k]-'a']);
        }
      }
      // cout << '\n';

      ans += totalCnt - maxcnt;
      iter++;
    }

    i = j;
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