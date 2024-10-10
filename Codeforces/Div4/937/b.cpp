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
    bool curr1 = true;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++){
        
        bool curr2 = curr1;
        for (int j = 0; j < 2 * n; j++){
            if (j % 2 == 0) curr2 = !curr2;
            if (!curr2) cout << '#';
            else cout << '.';
        }
        cout << '\n';
        cnt++;
        if (cnt == 2) {
            curr1 = !curr1;
            cnt = 0;
        }
    }
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