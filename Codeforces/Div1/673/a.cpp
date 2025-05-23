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
  vector<vector<int>> numByInds(n, vector<int>());
  for(int i = 0; i < n; i++) {
    int num; cin >> num;
    numByInds[num-1].push_back(i);
  } 
  int ansPtr = n;
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    if (numByInds[i].size() == 0) continue;
    int lowestSeg = 1;
    int prev = -1;
    for (int j = 0; j < numByInds[i].size(); j++){
      lowestSeg = max(lowestSeg, numByInds[i][j] - prev);
      prev = numByInds[i][j];
    }
    lowestSeg = max(lowestSeg, n - prev);
    while (ansPtr >= lowestSeg)
      ans[--ansPtr] = i+1;
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
