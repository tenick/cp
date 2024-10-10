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

// Recursive function to return gcd of a and b
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
  

void solve(){
    ll n, x, y;
    cin >> n >> x >> y;

    ll xamt = n / x;
    ll yamt = n / y;
    ll minus = n / lcm(x, y);

    xamt -= minus;
    yamt -= minus;
    //cout << "xamt: " << xamt << " yamt: " << yamt << '\n';

    ll total = 0;
    ll end = n - xamt;
    total += xamt > 0 ? n * (n + 1) / 2 - (end * (end + 1)) / 2 : 0;
    total -= yamt > 0 ? yamt * (yamt + 1) / 2 : 0;
    cout << total << '\n';
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