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
    int n, m;
    cin >> n >> m;
    vector<int> slopes(n);
    for (int& i : slopes) cin >> i;
    sort(slopes.begin(), slopes.end());

    while (m--){
        double a, b, c;
        cin >> a >> b >> c;

        int l=1, r=slopes.size();
        bool found = false;
        while (l <= r) {
            int mid = (l + r) / 2;
            double slope = slopes[mid-1];
            
            // check if slope intersects with parabola
            double b2 = b - slope;
            double discriminant = (b2 * b2) - (4 * a * c);
            if (discriminant < 0){ // no intersection
                cout << "YES\n";
                cout << slope << '\n';
                found = true;
                break;
            }
            else {
                double d2 = sqrt(discriminant);
                double root1 = (-b2 + d2) / (a * 2);
                double root2 = (-b2 - d2) / (a * 2);
                if (root1 > 0 && root2 > 0){ // make the slope smaller
                    r = mid - 1;
                }
                else if (root1 < 0 && root2 < 0){ // make the slope bigger
                    l = mid + 1;
                }
                else {
                    // impossible
                    break;
                }
            }
        }
        if (!found) cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}