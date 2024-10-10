#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, vector<int>>> nodesByCostAndEdges(1, {1, vector<int>()});
    int totalStations = 1;

    for (int i = 0; i < n; i++){
        char event;
        if (event == '+'){
            int v, x;
            cin >> v >> x;
            nodesByCostAndEdges[v-1].second.push_back(nodesByCostAndEdges.size());
            nodesByCostAndEdges.push_back({x, vector<int>()});
        }
        else {
            int u, v, k;
            cin >> u >> v >> k;
        }
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
