#include <iomanip>
#include <iostream>
#include <sstream>
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

// #define ONLINE_JUDGE

string xmas = "MAS";

void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  string line;
  vector<string> wordgrid;
  while (getline(cin, line)) {
    if (line.empty())
      break;
    wordgrid.push_back(line);
  }
  int cnt = 0;
  for (int i = 1; i < wordgrid.size() - 1; i++) {
    for (int j = 1; j < wordgrid[0].size() - 1; j++) {
      string d1 = {wordgrid[i-1][j-1], wordgrid[i][j], wordgrid[i+1][j+1]};
      bool good1 = d1 == xmas;
      reverse(d1.begin(), d1.end());
      good1 |= d1 == xmas;

      string d2 = {wordgrid[i-1][j+1], wordgrid[i][j], wordgrid[i+1][j-1]};
      bool good2 = d2 == xmas;
      reverse(d2.begin(), d2.end());
      good2 |= d2 == xmas;

      if (good1 && good2) cnt++;
    }
  }

  cout << cnt << '\n';
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

