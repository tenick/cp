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
    string s;
    cin >> s;
    int hour = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, 2));
    string time = hour >= 12 ? "PM" : "AM";
    int newhour = hour % 12;
    if (newhour == 0) newhour = 12;
    string z1 = newhour < 10 ? "0" : "";
    string z2 = min < 10 ? "0" : "";
    cout << z1 << newhour << ":" << z2 << min << " " << time << '\n';
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