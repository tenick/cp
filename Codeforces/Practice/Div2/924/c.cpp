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
    int n, x;
    cin >> n >> x;
    set<int> ans;
    int num1 = n - x;
    if (num1 % 2 == 0){
        num1 /= 2;
        for (int i = 1; i <= floor(sqrt(num1)); i++){
            if (num1 % i == 0){
                if (i + 1 >= x)
                    ans.insert(i + 1);
                if (num1 / i + 1 >= x)
                    ans.insert(num1 / i + 1);
            }
        }
    }
    int num2 = n + x - 2;
    if (num2 % 2 == 0){
        num2 /= 2;
        for (int i = 1; i <= floor(sqrt(num2)); i++){
            if (num2 % i == 0){
                if (i + 1 >= x)
                    ans.insert(i + 1);
                if (num2 / i + 1 >= x)
                    ans.insert(num2 / i + 1);
            }
        }
    }

    cout << ans.size() << '\n';
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