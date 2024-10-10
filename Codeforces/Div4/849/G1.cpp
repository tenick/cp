#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        ll n, c;
        cin >> n >> c;

        vector<ll> costs(n);
        priority_queue<ll, vector<ll>, std::greater<ll>> ascendingCosts;
        for (int i = 0; i < n; i++)
            cin >> costs[i];

        for (int i = 0; i < n; i++)
            ascendingCosts.push(costs[i] + i + 1);

        ll totalTeleports = 0;
        while (!ascendingCosts.empty()){
            ll cost = ascendingCosts.top();
            ascendingCosts.pop();
            if (cost > c) break;
            c -= cost;
            totalTeleports++;
        }

        cout << totalTeleports << '\n';
    }
}