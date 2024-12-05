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

  string s;
  cin >> s;

  int twos = 0;
  int threes = 0;
  ll sm = 0;
  for (char c : s) {
    int val = c - '0';
    sm += val;
    if (val == 2) twos++;
    if (val == 3) threes++;
  }
  // cout << "sum = " << sm << '\n';

  int mod = 9 - (sm % 9);
  if (mod == 9) mod = 0;
  // cout << "mod = " << mod << '\n';
  int res = mod;
  if (mod % 2 == 0){
    if (res == 0) {
      cout << "YES\n";
      return;
    }
    else {
      if (res == 2 && twos >= 1) {
        cout << "YES\n";
        return;
      }
      else if (res == 4 && twos >= 2) {
        cout << "YES\n";
        return;
      }
      else if ((res == 6 && twos >= 3) || (res == 6 && threes >= 1)) {
        cout << "YES\n";
        return;
      }
      else if ((res == 8 && twos >= 4) || (res == 8 && threes >= 1 && twos >= 1)){
        cout << "YES\n";
        return;
      }
    }
  }
  else {
    if ((res == 1 && twos >= 5) || (res == 1 && threes >= 1 && twos >= 2)) {
      cout << "YES\n";
      return;
    }
    if ((res == 3 && twos >= 6) || (res == 3 && threes >= 2) || (res == 3 && threes >= 1 && twos >= 3)) {
      cout << "YES\n";
      return;
    }
    if ((res == 5 && twos >= 7) || (res == 5 && threes >= 2 && twos >= 1) || (res == 5 && threes >= 1 && twos >= 4)){
      cout << "YES\n";
      return;
    }
    if ((res == 7 && twos >= 8) || (res == 7 && threes >= 2 && twos >= 2) || (res == 7 && threes >= 1 && twos >= 5)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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

