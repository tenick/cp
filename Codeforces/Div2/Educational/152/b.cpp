#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> monsters(n);
    for (int i = 0; i < n; i++) {
        int health;
        cin >> health;
        monsters[i] = {health, i+1};
    }
    for (int i = 0; i < n; i++){
        monsters[i].first %= k;
        if (monsters[i].first == 0) cout << (i+1) << " ";
    }

     // this comparator will sort column 1, THEN column 2
    sort(begin(monsters), end(monsters),
    [&](const auto &a, const auto &b)
    {
      return a.first > b.first || (!(b.first > a.first) && a.second < b.second);
// if for 3 columns, return a[0] < b[0] || (a[0] <= b[0] && a[1] < b[1]) || (a[0] <= b[0] && a[1] <= b[1] && a[2] < b[2])	
    });

    for (auto& i : monsters) {
        if (i.first == 0) continue;
        cout << i.second << ' ';
    }
    cout << '\n';

    //for (int i = 0; i < n; i++)
    //    cout << monsters[i].first << ", " << monsters[i].second << " | ";
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