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
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
void solve(){
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
 
    m = max(0, m % k + max(0, m / k - ak) * k - a1);
    int fancyUsed = m / k;
    m %= k;

    if (m != 0){
        if (a1 >= k - m){
            fancyUsed++;
        }
        else {
            fancyUsed += m;
        }
    }

    cout << fancyUsed << '\n';
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