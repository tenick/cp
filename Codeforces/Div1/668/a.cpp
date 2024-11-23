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
  bool possible = true;
  for (int i = 0; i < k; i++) {
    bool found0 = s[i] == '0';
    bool found1 = s[i] == '1';
    for (int j = i + k; j < n; j+=k) {
      found0 |= s[j] == '0';
      found1 |= s[j] == '1';
    }
    if (found0 && found1) {
      possible = false;
      break;
    }
    if (s[i] == '?'){
      if (found0) s[i] = '0';
      if (found1) s[i] = '1';
    }
  }
  int curr0 = 0;
  int curr1 = 0;
  for (int i = 0; i < k; i++) {
    curr0 += s[i] == '0';
    curr1 += s[i] == '1';
  }
  if (curr0 > k/2 || curr1 > k/2) possible = false;
  if (possible) cout << "YES\n";
  else cout << "NO\n";
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
