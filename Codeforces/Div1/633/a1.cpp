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

// O(n) solution
void solve(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int& i : arr) cin >> i;
  vector<int> smallestAt(n, INT_MAX);
  int currSmallest = INT_MAX;
  for (int i = n-1; i >= 0; i--) {
    smallestAt[i] = min(smallestAt[i], currSmallest);
    currSmallest = min(currSmallest, arr[i]); 
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= smallestAt[i]) continue;
    ans = max(ans, abs(arr[i] - smallestAt[i]));
  }
  int cnt = 0;
  int powsum = 0;
  int pp = 1;
  while (powsum < ans) {
    powsum += pp;
    pp *= 2;
    cnt++;
  }
  cout << cnt << '\n';
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
