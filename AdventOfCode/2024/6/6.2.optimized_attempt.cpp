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

  vector<vector<vector<int>>> visited(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(4, 0)));
  // simulate
  int steps = 1;
  while (true){
    visited[r][c][guardState] = steps++;
    auto& dir = dirs[guardState];
    int newr = r + dir[0], newc = c + dir[1];
    if (newr >= 0 && newr < grid.size() && newc >= 0 && newc < grid[0].size()) {
      if (grid[newr][newc] == '#') {
        // visited[r][c][guardState] = steps++;
        guardState++;
        guardState %= 4;
        continue;
      }
    }
    else break;
    r = newr;
    c = newc;
  }

  // count all possible new obstructions
  int ans = 0;
  int obscnt = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      obscnt += grid[i][j] == '#';
      if (grid[i][j] != '.') {
        cout << grid[i][j];
        continue;
      }

      bool found = false;
      for (int k = 0; k < 4; k++) {
        if (found) 
          break;

        int newr = i + dirs[k][0], newc = j + dirs[k][1];
        if (newr < 0 || newr >= grid.size() || newc < 0 || newc >= grid[i].size() || grid[newr][newc] == '#') 
          continue;

        int opp = (k + 2) % 4;
        int stepAtOpp = visited[newr][newc][opp];
        if (!stepAtOpp) 
          continue;

        int oppnext = (opp + 1) % 4;
        int statehops = 0;
        while (statehops < 1000000) {
          int stepAtOppnext = visited[newr][newc][oppnext];
          if (stepAtOppnext) {
            found = stepAtOppnext < stepAtOpp;
            break;
          }
          newr += dirs[oppnext][0];
          newc += dirs[oppnext][1];
          if (newr >= 0 && newr < grid.size() && newc >= 0 && newc < grid[i].size() ) {
            if (grid[newr][newc] == '#') {
              newr -= dirs[oppnext][0];
              newc -= dirs[oppnext][1];
              oppnext++;
              oppnext %= 4;
              statehops++;
            }
          }
          else break;
        }
      }
      if (found) {
        ans++;
        cout << 'O';
      }
      else cout << grid[i][j];
    }
    cout << '\n';
  }

  cout << ans << '\n';
  cout << obscnt << '\n';
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

