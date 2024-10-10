
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
 
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--){
        int n, c;
        cin >> n >> c;
 
        vector<int> costs(n);
        for (int i = 0; i < n; i++) cin >> costs[i];
 
        if (n == 1) {
            cout << (costs[0] + 1 <= c) << '\n';
            continue;
        }
 
        vector<pair<int, int>> ascendingCosts;
        ascendingCosts.reserve(n);
 
        int nhalf = n >> 1;
        for (int i = 0; i < nhalf; i++){
            ascendingCosts.push_back({costs[i] + i + 1, i});
            ascendingCosts.push_back({costs[n - i - 1] + i + 1, n - i - 1});
        }
        if (n % 2 == 1) ascendingCosts.push_back({costs[nhalf] + nhalf + 1, nhalf});
 
        sort(ascendingCosts.begin(), ascendingCosts.end());
 
        vector<ll> ps;
        ps.reserve(n);
        vector<int> portalUsedAt(n);
        ps.push_back(0);
        for (int i = 0; i < n; i++){
            auto& p = ascendingCosts[i];
            ps.push_back(ps[i] + p.first);
            portalUsedAt[p.second] = i;
        }
 
        // for (int i = 0; i < n; i++){
        //     cout << ascendingCosts[i].first << " | " << ascendingCosts[i].second << " sum here: " << ps[i+1];
        //     cout << '\n';
        // }
 
        int maxTotalTeleps = 0;
        bool wasPortalUsed = false;
        for (int i = 0; i < n; i++){
            int teleCost = costs[i] + i + 1;
            int newC = c - teleCost;
            //cout << "original coins: " << c << " new coins: " << newC << " (spent " << teleCost << " at portal #" << i << ")" << '\n';
            int l=0, r=n-1,mid;
            while (l <= r){
                wasPortalUsed = false;
                mid = (l + r) >> 1;

                ll sum = ps[mid+1];
                //cout << "mid: " << mid << " ";
                if (portalUsedAt[i] <= mid){
                    //cout << "portal #" << mid << " is already visited!\n";
                    int costAtThatInd = min(costs[i] + i + 1, costs[i] + n - i);
                    sum -= costAtThatInd;
                    wasPortalUsed = true;
                }
                
                //cout << " curr sum: " << sum << '\n';
                if (newC >= sum) {
                    if (l == mid) break;
                    l = mid;
                }
                else r = mid - 1;

                //cout << "new l: " << l << " new r: " << r << '\n';
            }

            if (r >= 0){
                if (l < r) {
                    ll sum2 = ps[l+2];
                    if (portalUsedAt[i] <= l+1){
                        int costAtThatInd = min(costs[i] + i + 1, costs[i] + n - i);
                        sum2 -= costAtThatInd;
                        wasPortalUsed = true;
                    }
                    if (newC >= sum2) l++;
                } 
                maxTotalTeleps = max(maxTotalTeleps, l+1+!wasPortalUsed);
            }
            else if (newC >= 0) maxTotalTeleps = max(maxTotalTeleps, 1);
            
            
 
            //cout << "curr teleps: " << maxTotalTeleps << '\n';
        }
 
        cout << maxTotalTeleps << '\n';
    }
}