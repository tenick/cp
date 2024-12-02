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

bool diff1to3(int a, int b){
  return a - b >= 1 && a - b <= 3;
}

void solve(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  vector<string> levels;
  string line;
  int safes = 0;
  while (getline(cin, line)){
    if (line.empty())
      break;
    istringstream iss(line);
    int lvl;
    vector<int> arr;
    while(iss >> lvl)
    {
      arr.push_back(lvl);
    }
    // check incr
    bool isincr = true;
    bool rem = true;
    int prev = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      if (diff1to3(arr[i], prev)) {
        prev = arr[i];
        continue;
      }
      if (rem) {
        rem = false;  
        bool currgood = (i - 2 >= 0 ? diff1to3(arr[i], arr[i-2]) : true) && (i + 1 < arr.size() ? diff1to3(arr[i+1], arr[i]) : true);
        bool prevgood = (i+1 < arr.size() ? diff1to3(arr[i+1], prev) : true);
        if (currgood && prevgood) prev = min(prev, arr[i]);
        if (currgood) prev = arr[i];
        if (currgood || prevgood) continue;
      }
      isincr = false;
      break;
    }
      
    // check decr
    bool isdecr = true;
    rem = true;
    prev = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      int diff = prev - arr[i];
      if (diff >= 1 && diff <= 3) {
        prev = arr[i];
        continue;
      }
      if (rem) {
        rem = false;
        bool currgood = (i - 2 >= 0 ? diff1to3(arr[i-2], arr[i]) : true) && (i + 1 < arr.size() ? diff1to3(arr[i], arr[i+1]) : true);
        bool prevgood = (i+1 < arr.size() ? diff1to3(prev, arr[i+1]) : true);
        if (currgood && prevgood) prev = max(prev, arr[i]);
        if (currgood) prev = arr[i];
        if (currgood || prevgood) continue;
      }
      isdecr = false;
      break;
    }

    if (isincr || isdecr) 
      safes++;
  }

  cout << safes << '\n';
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
