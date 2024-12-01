class Solution {
public:
    vector<int> calcTarget(int k, vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> ki(n);
        vector<vector<int>> nodesByNeighbors(n);
        for (auto& edge : edges) {
            nodesByNeighbors[edge[0]].push_back(edge[1]);
            nodesByNeighbors[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            queue<pair<int, pair<int, int>>> bfs;
            bfs.push({-1, {0, i}});
            int target = 0;
            while (!bfs.empty()) {
                auto top = bfs.front(); 
                bfs.pop();
                target++;
                int parent = top.first;
                int currk = top.second.first;
                if (currk == k) continue;
                
                int curr = top.second.second;
                for (int neighbor : nodesByNeighbors[curr]) {
                    if (neighbor == parent) continue;
                    bfs.push({curr, {currk+1, neighbor}});
                }
            }
            ki[i] = target;
        }
        return ki;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> k1 = calcTarget(k, edges1);
        vector<int> k2;
        if (k == 0) {
            return k1;
        }
        k2 = calcTarget(k-1, edges2);
        sort(k2.begin(), k2.end());
        for (int i = 0; i < k1.size(); i++) {
            k1[i] += k2.back();
        }
        
        return k1;
    }
};
