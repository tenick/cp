#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

typedef long long ll;

struct Tree {
    std::vector<Tree*> children;
    Tree* parent = nullptr;
    bool visited = false;
    int subTreeNodeCount = 1;
    int country;
    Tree(int country) : country(country) {}
    void addChild(Tree* child){
        children.push_back(child);
    }
};


// https://leetcode.com/contest/weekly-contest-320/problems/minimum-fuel-cost-to-report-to-the-capital/
ll minimumFuelCost(std::vector<std::vector<int>>& roads, int seats){
    if (roads.size() == 0)
        return 0;
    
    // build tree
    std::vector<Tree*> countries(roads.size() + 1, nullptr);
    for (auto& road : roads){
        if (countries[road[0]] == nullptr)
            countries[road[0]] = new Tree(road[0]);
        if (countries[road[1]] == nullptr)
            countries[road[1]] = new Tree(road[1]);
        countries[road[0]]->addChild(countries[road[1]]);
        countries[road[1]]->addChild(countries[road[0]]);
    }

    Tree* capital = countries[0];

    std::stack<Tree*> dfs;
    dfs.push(capital);

    while (!dfs.empty()){
        Tree* currNode = dfs.top();

        if (!currNode->visited){
            for (Tree* node : currNode->children){
                if (node == currNode->parent) continue;
                node->parent = currNode;
                dfs.push(node);
            }
            currNode->visited = true;
        }
        else {
            if (currNode->parent != nullptr)
                currNode->parent->subTreeNodeCount += currNode->subTreeNodeCount;
            dfs.pop();
        }
    }

    ll totalFuel = 0;
    for (int i = 1; i < countries.size(); i++){
        Tree* currCountry = countries[i];
        totalFuel += std::ceil((double)currCountry->subTreeNodeCount / seats);
    }

    return totalFuel;
}

int main(){
    std::vector<std::vector<int>> roads {{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}};
    roads = {{0,1}, {1,2}, {2,3}, {3,4}, {2,5}, {5,6}};
    int seats = 3;

    ll minFuel = minimumFuelCost(roads, seats);
    std::cout << minFuel << '\n';
    
}