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

typedef long long ll;
typedef unsigned long long ull;

int constructKey(int a, int b){
    int key = 0;
    int place = 1;
    while (a != 0){
        int dec = a % 10;
        key += dec * place;
        place *= 10;
        a /= 10;
    }
    while (b != 0){
        int dec = b % 10;
        key += dec * place;
        place *= 10;
        b /= 10;
    }
    return key;
}

bool traverse(int from, int to, vector<vector<pair<int, int>>>& nodesByEdgeWeight, map<int, set<int>>& edges) {
    for (auto& kvp : nodesByEdgeWeight[to]){
        int neighbor = kvp.first;
        int weight = kvp.second;
        if (edges.find(weight) == edges.end() || edges[weight].find(constructKey(to, neighbor)) == edges[weight].end())
            continue;
        if (neighbor == from) return true;
        if (traverse(from, neighbor, nodesByEdgeWeight, edges))
            return true;
    }
    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;

    auto cmp = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first > b.first; };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
    map<int, set<int>> edges;
    vector<vector<pair<int, int>>> nodesByEdgeWeight(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        nodesByEdgeWeight[u-1].push_back({v-1, w});
        pq.push({w, {u, v}});
        if (edges.find(w) == edges.end()) edges[w] = set<int>();
        edges[w].insert(constructKey(u, v));
    }

    while (pq.empty()){
        auto curr = pq.top();
        int weight = curr.first;
        int from = curr.second.first;
        int to = curr.second.second;
        if (edges.find(weight) == edges.end() || edges[weight].find(constructKey(from, to)) == edges[weight].end())
            continue;
        if (curr)
    }
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