#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    double pre = 1/log(2);
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        vector<pair<int, int>> ops;
        for (int i = 0; i < n; i++){
            int ans = ceil(log(a[i]) * pre);
            ans = pow(2, max(ans, 1));

            if (a[i] % ans != 0){
                int curr = ans - a[i] % ans;
                int deducted = 0;
                while (curr != 0){
                    int toDeduct = min(curr, a[i] + deducted);
                    deducted += toDeduct;
                    curr -= toDeduct;
                    ops.push_back({i + 1, toDeduct});
                }
            }
        }

        cout << ops.size() << '\n';
        for (auto& i : ops){
            cout << i.first << " " << i.second << '\n';
        }
    }
}