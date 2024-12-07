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

void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  string line;
  map<int, set<int>> pageByReqPage;
  while (getline(cin, line)) {
    if (line.empty()) break;
    istringstream iss(line);
    getline(iss, line, '|');
    int b = stoi(line); 
    getline(iss, line, '|');
    int a = stoi(line);

    if (pageByReqPage.find(a) == pageByReqPage.end())
      pageByReqPage[a] = set<int>();
    pageByReqPage[a].insert(b);
  }

  int ans = 0;
  while(getline(cin, line)){
    if (line.empty()) break;
    istringstream iss(line);
    vector<pair<int, int>> order;
    multiset<pair<int, int>> pagesAfter;
    int ind = 0;
    while(getline(iss,line,',')){
      if (line.empty()) break;
      order.push_back({stoi(line), ind});
      pagesAfter.insert(order.back());
      ind++;
    }

    bool good = true;
    for (int i = 0; i < order.size(); i++) {
      auto& page = order[i];

      auto currPage = pagesAfter.extract(page).value();
      int currPageInd = currPage.second;

      for (int reqPage : pageByReqPage[page.first]) {
        pair<int, int> toFind{reqPage, 0};
        if (pagesAfter.lower_bound(toFind) != pagesAfter.end()) {
          // check if valid found page
          auto found = *pagesAfter.lower_bound(toFind);
          if (found.first != reqPage)
            continue;
          
          // perform swap
          auto toSwapPage = pagesAfter.extract(found).value();
          int toSwapPageInd = toSwapPage.second;

          toSwapPage.second = currPageInd;
          order[currPageInd] = toSwapPage;
          pagesAfter.insert(toSwapPage);

          currPage.second = toSwapPageInd;
          order[toSwapPageInd] = currPage;
          pagesAfter.insert(currPage);

          good = false;
          i--;
          break;
        }
      }
    }

    if (!good)
      ans += order[order.size()/2].first;
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

