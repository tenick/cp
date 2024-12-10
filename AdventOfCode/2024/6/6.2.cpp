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

// #define ONLINE_JUDGE

vector<vector<int>> dirs {
  {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

bool isPossible(int r, int c, int guardState, vector<string>& grid) {
  vector<vector<vector<int>>> visited(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(4, 0)));
  // simulate
  int steps = 1;
  while (true){
    if (visited[r][c][guardState]) 
      return true;
    visited[r][c][guardState] = steps++;
    auto& dir = dirs[guardState];
    int newr = r + dir[0], newc = c + dir[1];
    if (newr >= 0 && newr < grid.size() && newc >= 0 && newc < grid[0].size()) {
      if (grid[newr][newc] == '#') {
        guardState++;
        guardState %= 4;
        continue;
      }
    }
    else break;
    r = newr;
    c = newc;
  }
  return false;
}

void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  vector<string> grid;
  string line;
  while (getline(cin, line)) {
    if (line.empty()) break;
    grid.push_back(line);
  }

  // locate the guard coordinates
  int r, c, guardState = 0;
  bool found = false;
  for (int i = 0; i < grid.size(); i++) {
    if (found) break;
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == '^') {
        r = i; c = j;
        found = true;
        break;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] != '.')
        continue;
      grid[i][j] = '#';
      if (isPossible(r, c, guardState, grid))
        ans++;
      grid[i][j] = '.';
    }
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

