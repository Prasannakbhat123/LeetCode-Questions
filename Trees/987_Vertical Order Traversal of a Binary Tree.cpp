#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
//   Definition for a binary tree node.
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
    // Vertical traversal: nodes are grouped by their horizontal distance (x).
    // Within the same column (x) they are ordered by their row (y), and when
    // multiple nodes share the same (x,y) position we output them in ascending
    // order of their values. To achieve this deterministically we perform a
    // BFS while tracking coordinates, and store values in a nested map:
    // map<x, map<y, multiset<val>>> so that iteration yields columns from left
    // to right, rows from top to bottom, and values sorted at the same position.
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Queue carries node and its (x,y) coordinates: x = horizontal distance,
        // y = depth (root has y = 0 and increases by 1 for each level).
        queue<pair<TreeNode*, pair<int,int>>> q;
        // Nested map: column -> row -> multiset of node values
        map<int, map<int, multiset<int>>> mpp;

        // Start BFS at root with coordinates (0,0)
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            TreeNode* node = it.first;
            int x = it.second.first;  // horizontal distance (column)
            int y = it.second.second; // depth (row)

            // Insert value into the structure. multiset ensures sorted order when
            // multiple nodes appear at the same (x,y).
            mpp[x][y].insert(node->val);

            if (node->left)  q.push({node->left,  {x-1, y+1}});
            if (node->right) q.push({node->right, {x+1, y+1}});
        }

        // Flatten the nested map into the required output format: for each column
        // (left to right), iterate rows (top to bottom) and append the sorted values.
        vector<vector<int>> ans;
        for (auto &col_pair : mpp) {
            vector<int> col;
            for (auto &row_pair : col_pair.second) {
                col.insert(col.end(), row_pair.second.begin(), row_pair.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};