#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
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
    ull n;
    cin >> n;

    ull l=1, r=4e9;
    while (l < r){
        ull balls = (l + r) / 2;
        ull flavors = balls * (balls - 1) / 2;

        // cout << "ball, flavors = " << balls << ", " << flavors << '\n';
        if (flavors >= n){
            r = balls;
            // cout << "setting r = " << balls << '\n';
        }
        else {
            l = balls + 1;
            // cout << "setting l = " << balls << '\n';
        }
    }

    ull flavors = l * (l - 1) / 2;
    if (flavors > n) l--;
    flavors = l * (l - 1) / 2;

    cout << l + (n - flavors) << '\n';
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