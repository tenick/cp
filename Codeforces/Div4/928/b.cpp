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

void solve(){
    int n;
    cin >> n;
    vector<string> grid;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        grid.push_back(s);
    }
    set<int> vals;
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (grid[i][j] == '1'){
                cnt++;
            }
        }
        if (cnt != 0)
            vals.insert(cnt);
    }
    if (vals.size() == 1) cout << "SQUARE\n";
    else cout << "TRIANGLE\n";
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