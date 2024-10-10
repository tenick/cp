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
    ll n, k, x;
    cin >> n >> k >> x;

    if (n * (n + 1) / 2 < x){
        cout << "NO\n";
        return;
    }
    
    if (k * (k + 1) / 2 > x){
        cout << "NO\n";
        return;
    }
    
    if ((k * (2 * (n - k + 1) + (k - 1))) / 2 < x){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

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