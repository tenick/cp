#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;

bool visited[100][100];

bool bfsPossible(int n, int m, int divisor, vector<vector<int>>& grid){
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        if (curr.first + 1 < n && grid[curr.first+1][curr.second] % divisor == 0 && !visited[curr.first+1][curr.second]){
            q.push({curr.first+1, curr.second});
            visited[curr.first+1][curr.second] = true;
        }
        if (curr.second + 1 < m && grid[curr.first][curr.second+1] % divisor == 0 && !visited[curr.first][curr.second+1]){
            q.push({curr.first, curr.second + 1});
            visited[curr.first][curr.second + 1] = true;
        }
    }

    return visited[n-1][m-1];
}
void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (auto& row : grid)
        for (int& i : row) cin >> i;
    
    int ans = 1;

    int toSearch = gcd(grid[0][0], grid[n-1][m-1]);
    for (int i = 1; i*i <= toSearch; i++) {
        if (toSearch % i != 0) continue;

        if (bfsPossible(n, m, i, grid)) ans = max(ans, i);
        if (bfsPossible(n, m, toSearch/i, grid)) ans = max(ans, toSearch/i);
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