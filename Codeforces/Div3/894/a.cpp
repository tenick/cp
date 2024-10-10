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
    int n, m;
    cin >> n >> m;

    vector<string> carpet(n);
    for (int i = 0; i < n; i++){
        cin >> carpet[i];
    }
    string toFind = "vika";
    int curr = 0;
    for (int c = 0; c < m; c++){
        if (curr == 4) break;
        for (int r = 0; r < n; r++){
            if (carpet[r][c] == toFind[curr]){
                curr++;
                break;
            }
        }
    }
    if (curr == 4){
        cout << "YES\n";
    }
    else cout << "NO\n";
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