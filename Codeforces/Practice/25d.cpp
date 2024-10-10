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

void unionByRank(){

}

int findParent(int node, vector<int>& parent){
    if (node == parent[node-1])
        return node;
    return parent[node-1] = findParent(parent[node-1], parent);
}

void solve(){
    int n;
    cin >> n;
    set<pair<int, int>> conflict;
    vector<int> parent(n);
    for (int i = 1; i <= n; i++)
        parent[i-1] = i;
    vector<int> rank(n, 0);

    while (--n){
        int u, v;
        cin >> u >> v;
        
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu == pv){
            conflict.insert({u, v});
            continue;
        }

        if (rank[pu-1] < rank[pv-1])
            swap(pu, pv);
        if (rank[pu-1] == rank[pv-1])
            rank[pu-1]++;
        parent[pv-1] = pu;
    }

    // compress paths, get connectible vertices
    vector<int> connect;
    set<int> seen;
    for (int i = 0; i < parent.size(); i++){
        int pu = findParent(i+1, parent);
        if (seen.find(pu) == seen.end()){
            connect.push_back(i+1);
            seen.insert(pu);
        }
    }
    cout << conflict.size() << '\n';
    int i = 0;
    for (auto kvp : conflict){
        cout << kvp.first << " " << kvp.second << " " << connect[i] << " " << connect[i+1] << '\n';
        i++;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //std::cout << std::setprecision(9); // use it for output that requires some precision

    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
}