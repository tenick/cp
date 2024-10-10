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

bool topSortRC(int currNode, vector<vector<int>>& potionByPrereq, vector<bool>& innerVisit, vector<bool>& visited, vector<int>& topSorted){
    if (visited[currNode]) return true;
    if (innerVisit[currNode])
        return false;
   
    innerVisit[currNode] = true;
    for (int prereqPotion : potionByPrereq[currNode])
        if (!topSortRC(prereqPotion, potionByPrereq, innerVisit, visited, topSorted)) return false;
   
    topSorted.push_back(currNode);
    visited[currNode] = true;


    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ull> pCost(n);
    for (ull& i : pCost) cin >> i;

    for (int i = 0; i < k; i++){
        int unli;
        cin >> unli;
        pCost[unli-1] = 0;
    }

    // construct nodesByEdges here
    vector<vector<int>> potionByPrereq(n);

    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        for (int j = 0; j < m; j++){
            int p;
            cin >> p;
            potionByPrereq[i].push_back(p-1);
        }
    }


    vector<int> topSorted;
    vector<bool> visited(n);
    vector<bool> innerVisit(n);


    bool possible = true;
    for (int i = 0; i < n; i++){
        if (!topSortRC(i, potionByPrereq, innerVisit, visited, topSorted)){
            possible = false;
            break;
        }
    }

    vector<ull> potionMinCost(n);
    for (int i : topSorted){
        if (potionByPrereq[i].size() == 0) potionMinCost[i] = pCost[i];
        else {
            ull prereqSum = 0;
            for (int j : potionByPrereq[i]){
                prereqSum += potionMinCost[j];
            }
            potionMinCost[i] = min(pCost[i], prereqSum);
        }
    }

    for (ull mincost : potionMinCost){
        cout << mincost << ' ';
    }
    cout << '\n';
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