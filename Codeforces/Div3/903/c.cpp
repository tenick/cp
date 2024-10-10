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
    vector<string> grid(n);
    for (string& s : grid) cin >> s;

    int cnt = n;
    int minOps = 0;
    for (int i = 0; i < n / 2; i++){
        vector<string> aroundVec(4);
        // 0 - top;
        // 1 - right;
        // 2 - bottom;
        // 3 - left;
        for (int j = 0; j < cnt; j++){
            aroundVec[0].push_back(grid[i][i + j]);
            aroundVec[1].push_back(grid[i + j][n - 1 - i]);
            aroundVec[2].push_back(grid[n - 1 - i][n - 1 - i - j]);
            aroundVec[3].push_back(grid[n - 1 - i - j][i]);
        }
        

        for (int j = 0; j < cnt - 1; j++){
            char maxC = 'a';
            for (int k = 0; k < 4; k++){
                maxC = max(maxC, aroundVec[k][j]);
            }
            for (int k = 0; k < 4; k++){
                minOps += maxC - aroundVec[k][j];
            }
        }
        cnt -= 2;
    }
    cout << minOps << '\n';
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