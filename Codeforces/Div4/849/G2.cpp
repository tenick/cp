#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pic;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    auto cmp = [](pic a, pic b) { return a.second > b.second; };
    priority_queue<pic, vector<pic>, decltype(cmp)> pq(cmp);

    while (t--){
        int n, c;
        cin >> n >> c;

        if (n == 2) {
            cout << "cost: " << c << '\n';
        }

        vector<int> costs(n);
        
        for (int i = 0; i < n; i++){
            cin >> costs[i];
            cout << "cost " << i+1 << ": " << costs[i] << '\n';
        }

        priority_queue<pic, vector<pic>, decltype(cmp)> ascendingCosts(cmp);
        for (int i = 0; i < n; i++){
            if (n == 2) {
                cout << i << " | " << costs[i] + i + 1 << '\n';
            }
            ascendingCosts.push({i, costs[i] + i + 1});
        }

        int totalTeleports = 0;
        vector<bool> seen(n);
        pic firstTeleport = ascendingCosts.top();
        ascendingCosts.pop();
        if (firstTeleport.second > c) {
            cout << "0\n";
            continue;
        }
        else{
            seen[firstTeleport.first] = true;
            c -= firstTeleport.second;
            totalTeleports++;
            if (n == 2){
                cout << "first tele: " << firstTeleport.first << " | " << firstTeleport.second << '\n';
            }
        }

        for (int i = n - 1; i >= 0; i--)
            ascendingCosts.push({i, costs[i] + (n - i)});

        while (!ascendingCosts.empty()){
            pic cost = ascendingCosts.top();
            ascendingCosts.pop();

            if (seen[cost.first]) continue;
            seen[cost.first] = true;

            if (cost.second > c) break;
            c -= cost.second;
            totalTeleports++;
        }

        cout << totalTeleports << '\n';
    }
}