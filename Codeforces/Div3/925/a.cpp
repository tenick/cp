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
    string s = "aaa";
    if (n == 27){
        cout << "aay\n";
        return;
    }
    int i = 2;
    while (n / 26){
        if (n == 26) break;
        n -= 26;
        s[i--] = 'z';
    }

    if (i == 2){
        n -= 2;
        s[2] = 'a' + n - 1;
        cout << s << '\n';
        return;
    }
    if (i == 1){
        s[i--] = 'a' + (n - 2);
        n = 1;
    }
    s[i] = 'a' + (n - 1);
    cout << s << '\n';
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