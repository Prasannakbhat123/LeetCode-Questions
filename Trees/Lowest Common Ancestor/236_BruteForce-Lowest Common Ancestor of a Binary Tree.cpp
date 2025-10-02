#include <iostream>
#include <vector>

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
    // Helper function to get path from root to a node with value x
    // Uses DFS, pushing nodes onto `path` while descending and popping when backtracking.
    // Returns true if a node with value x is found in the subtree rooted at `root`.
    bool getPath(TreeNode *root, vector<TreeNode*> &path, int x) {
        if (!root)
            return false;

        path.push_back(root);

        if (root->val == x)
            return true;

        // Search left or right; if found, keep current path; otherwise pop and backtrack.
        if (getPath(root->left, path, x) || getPath(root->right, path, x))
            return true;

        path.pop_back(); // Backtrack if x not in this path
        return false;
    }

    // Brute-force approach: compute paths from root to both nodes, then compare paths
    // to find the last common node. This method assumes node values are unique (uses value to find nodes).
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        // Get paths from root to p and q (by value)
        getPath(root, path1, p->val);
        getPath(root, path2, q->val);

        // Compare the paths to find the last common node
        int i = 0;
        while (i < (int)path1.size() && i < (int)path2.size() && path1[i] == path2[i]) {
            i++;
        }

        // i-1 is the index of the last shared ancestor on the paths
        return path1[i - 1];
    }
};
