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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    ll n;
    cin >> n;
    ll curr = 0;
    ll longest = 0;
    ll upperbound = ceil(sqrt(n));
    //cout << "max int for n=" << n << ": " << upperbound << '\n';
    for (ll i = 1; i <= 1000; i++){
        if (n % i == 0){
            curr++;
        }
        else {
            longest = max(longest, curr);
            curr = 0;
        }
    }
    cout << max(longest, curr) << '\n';
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