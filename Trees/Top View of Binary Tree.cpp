#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
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
    // Top view: for each horizontal distance (column) we want the first node seen
    // when looking top-down. Performing a BFS (level-order) and recording the first
    // occurrence at each horizontal distance yields the correct visible nodes.
    vector<int> topView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        // Map horizontal distance -> first node value seen at that distance
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            TreeNode* node = it.first;
            int line = it.second; // horizontal distance (column)

            // Only set the value if this horizontal distance hasn't been seen yet.
            // Because BFS is level-order, the first time we see a horizontal distance
            // corresponds to the topmost node for that column.
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->val;
            }

            if (node->left)  q.push({node->left,  line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        // Collect results from leftmost to rightmost horizontal distance
        for (auto &p : mpp) ans.push_back(p.second);
        return ans;
    }
};
