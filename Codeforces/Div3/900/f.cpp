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

void get_pfs(int n, map<int, int>& pFactorByCount)
{
    if (n % 2 == 0 && pFactorByCount.find(2) == pFactorByCount.end())
        pFactorByCount[2] = 0;
   
    while (n % 2 == 0)
    {
        pFactorByCount[2]++;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if (pFactorByCount.find(i) == pFactorByCount.end())
                pFactorByCount[i] = 0;
        while (n % i == 0)
        {
            pFactorByCount[i]++;
            n = n/i;
        }
    }
   
    if (n > 2){
        if (pFactorByCount.find(n) == pFactorByCount.end())
            pFactorByCount[n] = 0;
        pFactorByCount[n]++;
    }
}


int countDivisors(map<int, int>& pFactorByCount) {
    int ans = 1;
    for (auto& kvp : pFactorByCount)
        ans *= (kvp.second + 1);
    return ans;
}

bool answer(map<int, int>& pFactorByCount){
    int cnt = countDivisors(pFactorByCount);
    for (auto kvp : pFactorByCount){
        if (cnt == 1) break;
        while (kvp.second--){
            if (cnt % kvp.first != 0){
                break;
            }
            cnt /= kvp.first;
            if (cnt == 1) break;
        }
    }
    return cnt == 1;
}

void solve(){
    int N, q;
    cin >> N >> q;
    ull n = N;
    map<int, int> pFactorByCountOrig;
    get_pfs(N, pFactorByCountOrig);
    map<int, int> pFactorByCount = pFactorByCountOrig;
    while (q--){
        int k;
        cin >> k;
        if (k == 1){
            int x;
            cin >> x;
            n *= x;
            get_pfs(x, pFactorByCount);
            if (answer(pFactorByCount)) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            n = N;
            pFactorByCount = pFactorByCountOrig;
        }
    }
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