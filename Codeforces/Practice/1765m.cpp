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
 
typedef long long ll;
typedef unsigned long long ull;
 
void solve(){
    int n;
    cin >> n;
    int ans = 1e9;
    for (int i = 1; i <= floor(sqrt(n)); i++){
        if (n % i == 0){
            int d1 = i;
            if ((n - d1) % d1 == 0){
                int a = n - d1;
                int b = d1;
                if (a > 0 && b > 0)
                    ans = min(ans, max(a, b));
            }

            int d2 = n / i;
            if ((n - d2) % d2 == 0){
                int a = n - d2;
                int b = d2;
                if (a > 0 && b > 0)
                    ans = min(ans, max(a, b));
            }
        }
    }
    cout << n - ans << " " <<  ans << '\n';
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