class Solution {
public:
    vector<int> calcLevels(vector<vector<int>>& edges, vector<int>& nodeLvls) {
        int n = edges.size()+1;
        vector<int> ki(n);
        vector<vector<int>> nodesByNeighbors(n);
        for (auto& edge : edges) {
            nodesByNeighbors[edge[0]].push_back(edge[1]);
            nodesByNeighbors[edge[1]].push_back(edge[0]);
        }
        vector<int> levels;
        int clvl = 0;
        int cntlvl = 0;
        queue<pair<int, pair<int, int>>> bfs;
        bfs.push({clvl, {-1, 0}});
        while (!bfs.empty()) {
            auto top = bfs.front();
            bfs.pop();
            int currlvl = top.first;
            if (currlvl != clvl) {
                levels.push_back(cntlvl);
                clvl = currlvl;
                cntlvl = 0;
            }
            cntlvl++;
            int parent = top.second.first;
            int curr = top.second.second;
            nodeLvls[curr] = levels.size() % 2;

            for (int neighbor : nodesByNeighbors[curr]) {
                if (parent == neighbor) continue;
                bfs.push({clvl+1, {curr, neighbor}});
            }
        }
        if (cntlvl != 0) levels.push_back(cntlvl);

        return levels;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<int> nodeLvls1(n);
        vector<int> lvl1 = calcLevels(edges1, nodeLvls1);
        vector<int> nodeLvls2(m);
        vector<int> lvl2 = calcLevels(edges2, nodeLvls2);
        
        int cntodd = 0;
        int cnteven = 0;
        for (int i = 0; i < lvl1.size(); i++) {
            if (i % 2 == 0)
                cnteven += lvl1[i];
            else cntodd += lvl1[i];
        }
        int cntodd2 = 0;
        int cnteven2 = 0;
        for (int i = 0; i < lvl2.size(); i++) {
            if (i % 2 == 0)
                cnteven2 += lvl2[i];
            else cntodd2 += lvl2[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nodeLvls1[i] == 0 ? cnteven : cntodd;
            ans[i] += max(cntodd2, cnteven2);
        }

        return ans;
    }
};
