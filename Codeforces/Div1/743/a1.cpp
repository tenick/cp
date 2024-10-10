#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


bool topSortRC(int currNode, vector<vector<int>>& nodesByEdges, vector<bool>& innerVisit, vector<bool>& visited, vector<int>& topSorted){
    if (visited[currNode]) return true;
    if (innerVisit[currNode])
        return false;
    
    innerVisit[currNode] = true;
    for (int neighborNode : nodesByEdges[currNode])
        if (!topSortRC(neighborNode, nodesByEdges, innerVisit, visited, topSorted)) return false;
    
    topSorted.push_back(currNode);
    visited[currNode] = true;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        
        vector<vector<int>> chPrereq(n, vector<int>());
        vector<vector<int>> chNextRead(n, vector<int>());
        for (int i = 0; i < n; i++){
            int prqCnt;
            cin >> prqCnt;
            for (int j = 0; j < prqCnt; j++){
                int prq;
                cin >> prq;
                chPrereq[i].push_back(prq-1);
                chNextRead[prq-1].push_back(i);
            }
        }

        vector<int> topSorted;
        vector<bool> visited(n);
        vector<bool> innerVisit(n);

        bool possible = true;
        for (int i = 0; i < n; i++){
            if (!topSortRC(i, chPrereq, innerVisit, visited, topSorted)){
                possible = false;
                break;
            }
        }
        if (possible) {
            vector<int> dp(n, 0);
            int ans = 0;
            for (int ch : topSorted){
                for (int nextCh : chNextRead[ch]){
                    if (ch > nextCh) dp[nextCh] = max(dp[nextCh], dp[ch] + 1);
                    else  dp[nextCh] = max(dp[nextCh], dp[ch]);
                }
                ans = max(ans, dp[ch]);
            }
            //cout << "dp: ";
            //for (int i : dp) cout << i << " ";
            //cout << '\n';
            cout << ans + 1 << '\n';
        }
        else cout << -1 << '\n';
    }
}
