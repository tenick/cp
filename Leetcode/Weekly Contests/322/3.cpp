#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

class Node {
public:
    bool visited = false;
    vector<pair<Node*, int>> roadCost;
    void AddRoad(Node* node, int cost){
        roadCost.push_back({node, cost});
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> dirs;
        vector<Node*> cityNodes(n, nullptr);
        for (auto i : roads){
            if (cityNodes[i[0] - 1] == nullptr){
                cityNodes[i[0] - 1] = new Node();
            }
            if (cityNodes[i[1] - 1] == nullptr){
                cityNodes[i[1] - 1] = new Node();
            }
            cityNodes[i[0] - 1]->AddRoad(cityNodes[i[1] - 1], i[2]);
            cityNodes[i[1] - 1]->AddRoad(cityNodes[i[0] - 1], i[2]);
        }
        
        stack<Node*> dfs;
        dfs.push(cityNodes[0]);
        int score = 100000;
        while (!dfs.empty()){
            Node* currNode = dfs.top();
            currNode->visited = true;
            
            dfs.pop();
            for (auto i : currNode->roadCost){
                if (!i.first->visited){
                    cout << i.second << '\n';
                    dfs.push(i.first);
                    score = min(score, i.second);
                }
            }
        }
        return score;
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> roads = {{1,2,2},{1,3,4},{3,4,7}};
    //roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    int ans = s.minScore(n, roads);
    cout << ans << '\n';
}
