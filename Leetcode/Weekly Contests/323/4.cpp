#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        vector<int> answer(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++){
            stack<pair<int, int>> s;
            int pts = 0;
            s.push({0, 0});
            visited[0][0] = i;
            
            // perform dfs for each query
            while (!s.empty()){
                pair<int, int> rc = s.top();
                s.pop();
                int r = rc.first;
                int c = rc.second;
                
                // check if can add point (and thus can add unqueued/unvisited neighbors)
                if (queries[i] > grid[r][c]){
                    pts++;

                    // top
                    if (r > 0 && visited[r - 1][c] != i){
                        s.push({r - 1, c});
                        visited[r - 1][c] = i;
                    }
                    // bottom
                    if (r < grid.size() - 1 && visited[r + 1][c] != i){
                        s.push({r + 1, c});
                        visited[r + 1][c] = i;
                    }
                    // left
                    if (c > 0 && visited[r][c - 1] != i){
                        s.push({r, c - 1});
                        visited[r][c - 1] = i;
                    }
                    // right
                    if (c < grid[0].size() - 1 && visited[r][c + 1] != i){
                        s.push({r, c + 1});
                        visited[r][c + 1] = i;
                    }
                }
            }
            answer[i] = pts;
        }
        return answer;
    }
};

int main(){
    for (int i = 0; i < 1000000000; i++);
    cout << "done\n";

    
}