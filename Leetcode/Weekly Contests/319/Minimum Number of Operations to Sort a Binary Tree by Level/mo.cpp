#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int countMinOp(vector<int> treeLevel){
        unordered_map<int, int> map;
        vector<int> preSortIndices;
        int minSwapOp = 0;

        for (int i = 0; i < treeLevel.size(); i++)
            map[treeLevel[i]] = i;
        sort(treeLevel.begin(), treeLevel.end());
        for (int i = 0; i < treeLevel.size(); i++)
            preSortIndices.push_back(map[treeLevel[i]]);

        // -1 == visited
        for (int i = 0; i < preSortIndices.size(); i++){
            if (preSortIndices[i] >= 0){
                int currNum = preSortIndices[i];
                preSortIndices[i] = -1;
                while (true){
                    if (preSortIndices[currNum] == -1)
                        break;

                    int temp = preSortIndices[currNum];
                    preSortIndices[currNum] = -1;
                    currNum = temp;
                    minSwapOp++;
                }
            }
        }

        return minSwapOp;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int currSize = 1;
        int operations = 0;
        while (!q.empty()){
            vector<int> toCountVec;
            for (int i = 0; i < currSize; i++){
                TreeNode* currTreeNode = q.front();
                q.pop();
                if (currTreeNode->left != nullptr){
                    q.push(currTreeNode->left);
                    toCountVec.push_back(currTreeNode->left->val);
                }
                if (currTreeNode->right != nullptr){
                    q.push(currTreeNode->right);
                    toCountVec.push_back(currTreeNode->right->val);
                }
            }
            currSize = toCountVec.size();
            operations += countMinOp(toCountVec);
        }
        return operations;
    }
};


// can be helpful to solve first: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// orig problem: https://leetcode.com/contest/weekly-contest-319/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
int main(){
    TreeNode* tree = new TreeNode(1, 
        new TreeNode(4, new TreeNode(7), new TreeNode(6)), new TreeNode(3, new TreeNode(8, new TreeNode(9), nullptr), new TreeNode(5, new TreeNode(10), nullptr)));
    
    Solution s;
    int minNoOfOp = s.minimumOperations(tree);
    cout << minNoOfOp << '\n';
}