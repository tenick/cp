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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve(){
    int n;
    cin >> n;

    int ans = 0;
    set<int> positions;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            positions.insert(j);

            int maxterm = i * j;
            int currans = 0;
            
            for (int k = n; k >= 1; k--){
                if (k == i) continue;
                int pair = min(n, maxterm / k);


                while (pair >= 1 && positions.find(pair) != positions.end()){
                    pair--;
                }


                currans += k * pair;
                positions.insert(pair);
                if (pair == 0) break;
            }

            ans = max(ans, currans);

            positions.clear();
        }
    }

    cout << ans << '\n';
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