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

unordered_map<int, int> pFactorByCount;
 
void get_pfs(int n)
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


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& i : nums) cin >> i;

    for (int i : nums) get_pfs(i);

    bool possible = true;
    for (auto& kvp : pFactorByCount){
        if (kvp.second % n != 0){
            possible = false;
            break;
        }
    }

    pFactorByCount.clear();
    if (possible) cout << "YES";
    else cout << "NO";
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


