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
    string s;
    cin >> s;
    int r1 = 0;
    for (char c : s)
        r1 += c=='1';
    int l0 = 0;
    
    float best = 1e9;
    int ans = 1e9;
    for (int i = 0; i <= n; i++){
        if (i != 0) {
            if (s[i-1] == '0') l0++;
            else r1--;
        }
        
        
        int lx = i;
        int rx = n - i;
        
        if (l0 >= (lx + 1) / 2 && r1 >= (rx + 1) / 2){
            if (abs((float)n / 2 - i) < best){
                best = abs((float)n / 2 - i);
                ans = i;
            }
        }
        
    }
    cout << ans << '\n';

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