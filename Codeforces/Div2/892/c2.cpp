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

    int maxCost = 0;
    for (int i = 1; i <= n; i++){
        for (int j = n; j >= 1; j--){
            int maxterm = i * j;
            set<int> vals;
            for (int k = 1; k <= n; k++) vals.insert(k);
            
            int totalCost = -maxterm;
            for (int k = n; k >= 1; k--){
                int pair = maxterm / k;
                if (pair == 0) break;
                
                auto iter = vals.lower_bound(pair);

                if (*iter != pair){
                    if (iter == vals.begin()) break;
                    iter--;
                }
                totalCost += *iter * k;
                vals.erase(iter);
            }

            maxCost = max(maxCost, totalCost);
        }
    }

    cout << maxCost << '\n';
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