#include <iostream>
#include <vector>
#include <set>
#include <utility>

typedef unsigned long long ull;

using namespace std;

int getNodesFallingPointsCount(int parentNode, int currNode, const vector<vector<int>>& nodesByEdges, vector<int>& nodesFallingPointsCount){
    int totalFallingPoints = 0;
    for (int neighbor : nodesByEdges[currNode]){
        if (neighbor == parentNode) continue;
        totalFallingPoints += getNodesFallingPointsCount(currNode, neighbor, nodesByEdges, nodesFallingPointsCount);
    }
    if (totalFallingPoints == 0) totalFallingPoints = 1;
    return nodesFallingPointsCount[currNode] = totalFallingPoints;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> nodesByEdges(n, vector<int>());
    for (int i = 0; i < n-1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        nodesByEdges[n1-1].push_back(n2-1);
        nodesByEdges[n2-1].push_back(n1-1);
    }
    int q;
    cin >> q;
    vector<pair<int, int>> assumptions;
    for (int i = 0; i < q; i++){
        int x,y;
        cin >> x >> y;
        assumptions.push_back({x, y});
    }

    vector<int> nodesFallingPointsCount(n, -1);
    getNodesFallingPointsCount(-1, 0, nodesByEdges, nodesFallingPointsCount);

    for (auto& assumption : assumptions) {
        ull ans = (ull)nodesFallingPointsCount[assumption.first-1] * nodesFallingPointsCount[assumption.second-1];
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
}