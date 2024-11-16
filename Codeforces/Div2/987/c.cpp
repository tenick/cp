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
  if (n % 2 == 0) {
    for (int i = 0; i < n/2; i++) {
      cout << (i+1) << " " << (i+1) <<' ';
    }
    cout << '\n';
    return;
  }
  if (n <= 26) {
    cout << -1 << '\n';
    return;
  }
  int curr = 2, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || i == 10 || i == 26) {
      cout << 1 << ' ';
      continue;
    }
    if (i == 23 || i == 27) {
      cout << 12 << ' ';
      continue;
    }
    cout << curr << ' ';
    cnt++;
    if (cnt == 2) {
      curr++;
      if (curr == 12) curr++;
      cnt = 0;
    }
  }
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
