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

void solve(){
    int n;
    cin >> n;
    vector<int> fence(n);
    for (int& i : fence) cin >> i;

    int curr = fence[0];
    if (curr != fence.size()){
        cout << "NO\n";
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (i + 1 == n){
            for (int from = curr-1; from >= 0; from--){
                if (fence[from] != i + 1){
                    cout << "NO\n";
                    return;
                }
            }
            break;
        }

        int plank = fence[i+1];
        if (curr == plank) continue;
        
        for (int from = curr-1; from >= curr - (curr - plank); from--){
            if (fence[from] != i + 1){
                cout << "NO\n";
                return;
            }
        }
        curr = plank;
    }

    cout << "YES\n";
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