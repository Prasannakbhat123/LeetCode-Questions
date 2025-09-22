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
    int maxi = 0;

    int height(TreeNode* root) {
        // Single-pass approach: compute height of subtree, and while unwinding
        // the recursion update `maxi` with the diameter passing through `root`.
        // This avoids the repeated height computations of the brute-force approach.

        // Base case: empty subtree has height 0
        if (root == NULL) return 0;

        // Recursively compute heights of left and right subtrees
        int lh = height(root->left);
        int rh = height(root->right);

        // The longest path through `root` (in edges) is lh + rh. Update global maxi.
        // Note: we store diameter in terms of number of edges between nodes.
        maxi = max(maxi, lh + rh);

        // Return height of this subtree to parent (1 + max of child heights)
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // Kick off recursion to populate `maxi` and return the result.
        height(root);
        return maxi;
    }
};
