#include <iostream>
#include <unordered_map>
#include <climits>
#include <cmath>
 
using namespace std;
typedef unsigned long long ll;
 
unordered_map<ll, ll> pFactorByCount;
 
void get_pfs(ll n)
{
    while (n % 2 == 0)
    {
        if (pFactorByCount.find(2) == pFactorByCount.end())
            pFactorByCount[2] = 0;
        pFactorByCount[2]++;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            if (pFactorByCount.find(i) == pFactorByCount.end())
                pFactorByCount[i] = 0;
            pFactorByCount[i]++;
            n = n/i;
        }
    }
    
    if (n > 2)
        pFactorByCount[n] = 1;
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while (t--){
        ll n, m;
        cin >> n >> m;
 
        pFactorByCount.clear();
 
        get_pfs(m);
 
        ll ans = ULLONG_MAX;
 
        for (auto& pf : pFactorByCount){
            ll count = 0;
            ll p = pf.first;
            while (p <= n) {
                count += n / p;
                p *= pf.first;
            }
            ans = min(ans, count / pf.second);
        }
 
        cout << ans << '\n';
    }    
}