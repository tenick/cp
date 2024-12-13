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

const int MOD = 1e9 + 7;
void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  string s;
  cin >> s;
  int n = s.size();
  int firsta = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      firsta = i;
      break;
    }
  }
  if (firsta == -1) {
    cout << 0 << '\n';
    return;
  }

  int currcnt = 0;
  bool isA = true;
  vector<int> cnts;
  for (int i = firsta; i < n; i++) {
    if (isA) {
      if (s[i] == 'a') {
        currcnt++;
      }
      else if (s[i] == 'b'){
        isA = false;
        cnts.push_back(currcnt);
        currcnt = 1;
      }
    }
    else {
      if (s[i] == 'a') {
        isA = true;
        currcnt = 1;
      }
    }
  }
  if (isA) 
    cnts.push_back(currcnt);
  ll ans = 0;
  for (int i = 0; i < cnts.size(); i++) {
    ans += cnts[i] + cnts[i] * ans;
    ans %= MOD;
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

