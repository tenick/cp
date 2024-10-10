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
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<ll> ps;
    ll curr = 0;
    for (ll i : a){
        curr += i;
        ps.push_back(curr);
    }

    cout << "da ps: ";
    for (int i : ps) cout << i << ' ';
    cout << '\n';

    vector<int> nearLeft(n);
    nearLeft[0] = -1;
    for (int i = 1; i < n; i++){
        if (a[i] == a[i-1]){
            if (nearLeft[i-1] == -1) nearLeft[i] = -1;
            else nearLeft[i] = nearLeft[i-1]+1;
        }
        else nearLeft[i] = 1;
    }

    cout << "da nearLeft: ";
    for (int i : nearLeft) cout << i << ' ';
    cout << '\n';

    vector<int> nearRight(n);
    nearRight[n-1] = -1;
    for (int i = n-2; i >= 0; i--){
        if (a[i] == a[i+1]){
            if (nearRight[i+1] == -1) nearRight[i] = -1;
            else nearRight[i] = nearRight[i+1]+1;
        }
        else nearRight[i] = 1;
    }

    cout << "da nearRight: ";
    for (int i : nearRight) cout << i << ' ';
    cout << '\n';

    for (int i = 2; i <= 2; i++){
        // binary search left
        int dist1 = -1;
        if (i > 0 && nearLeft[i-1] != -1){
            int startLeft = nearLeft[i-1];
            cout << "startleft = " << startLeft << '\n';
            auto isLeftPossible = [&](int mid) 
            { 
                ll total = ps[i] - a[i];
                ll prev = mid == 0 ? 0 : ps[mid-1];
                total -= prev;
                cout << "total = " << total << '\n';
                return total > a[i];
            };
            int l=0, r=i - startLeft;
            cout << "l=" << l << " r=" << r << '\n';
            int res = -1;
            while (l <= r){
                int mid = (l + r) / 2;
                cout << "mid = " << mid << '\n';

                if (isLeftPossible(mid)){
                    res = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if (isLeftPossible(l)) dist1 = i - l;
            else if (res != -1) dist1 = i - res;
        }

        // binary search right
        int startRight = nearRight[i];
        int dist2 = -1;
        cout << "startRight = " << startRight << '\n';
        if (startRight != -1){
            auto isRightPossible = [&](int mid) 
            { 
                ll total = ps[mid] - ps[i];
                cout << "total = " << total << '\n';
                return total > a[i];
            };

            int l=i+startRight, r=n-1;
            cout << "l=" << l << " r=" << r << '\n';
            int res = -1;
            while (l < r){
                int mid = (l + r) / 2;
                cout << "mid = " << mid << '\n';
                if (isRightPossible(mid)){
                    res = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if (isRightPossible(r)) dist2 = r - i;
            else if (res != -1) dist2 = res - i;
        }

        if (dist1 == -1 && dist2 == -1) cout << -1 << ' ';
        else {
            if (dist1 == -1) cout << dist2 << ' ';
            else if (dist2 == -1) cout << dist1 << ' ';
            else cout << min(dist1, dist2) << ' ';
        }
    }
    cout << '\n';
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