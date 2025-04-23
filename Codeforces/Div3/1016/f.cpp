#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> target(n);
    for (string& s : target) cin >> s;
    
    vector<vector<string>> nns(m, vector<string>(n));
    for (int i = 0; i < m; i++) {
        for (string& s : nns[i]) cin >> s;
    }
    
    vector<vector<bool>> matches(m, vector<bool>(n, false));
    int bestnnCnt = -1, bestnnI;
    vector<bool> visited(n, false);
    int visitcnt = 0;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            matches[i][j] = nns[i][j] == target[j];
            if (matches[i][j]) {
                if (!visited[j]) {
                    visitcnt++;
                    visited[j] = true;
                }
                cnt++;
            }
        }
        if (cnt > bestnnCnt) {
            bestnnCnt = cnt;
            bestnnI = i;
        }
    }
    
    if (visitcnt == n)
        cout << (n - bestnnCnt) * 2 + n << '\n';
    else cout << -1 << '\n';
 
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
