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

bool isPossible(int val, int a, int b){
    int curr = 1;
    while (curr <= val){
        int curr2 = 1;
        while (curr2 * curr <= val){
            if (curr2 * curr == val) return true;
            curr2 *= b;
        }
        curr *= a;
    }
    return false;
}

void solve(){
    int a, b, l;
    cin >> a >> b >> l;
    int cnt = 0;
    for (int d = 1; d <= int(sqrt(l)); d++){
        if (l % d == 0){
            int pair = l / d;
            cnt += isPossible(pair, a, b);
            if (pair == d) continue;
            cnt += isPossible(l / pair, a, b);
        }
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