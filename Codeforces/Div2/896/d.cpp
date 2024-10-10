#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;
    
    ll sum = 0;
    for (int i : arr) sum += i;
    if (sum % n != 0){
        cout << "NO\n";
        return;
    }
    sum /= n;

    multiset<int> xs;
    multiset<int> ys;
    for (int pi : arr){
        if (pi == sum){
            continue;
        }
        bool found = false;
        int target = sum - pi;
        for (int x = 0; x < 32; x++){
            for (int y = 0; y < 32; y++){
                if (x == y) continue;
                int val = (1 << y) - (1 << x); 
                if (val == target){
                    //cout << "found: " << val << '\n';
                    found = true;
                    xs.insert(x);
                    ys.insert(y);
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            cout << "NO\n";
            return;
        }
    }

    if (xs == ys){
        cout << "YES\n";
    }
    else cout << "NO\n";
    
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