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
    int maxi = INT_MIN;

    int height(TreeNode* root) {
        // This helper returns the maximum path sum starting at `root` and
        // extending downwards to one child (used by parent). Meanwhile, we
        // update `maxi` to record the best path seen anywhere in the tree.

        // Base case: empty subtree contributes 0 when extending upwards
        if (root == NULL) return 0;

        // We take max(0, ...) for child contributions because if a child's
        // best downward path is negative, it's better to ignore it (choose 0)
        // rather than include it in a larger path.
        int lh = max(0,height(root->left));
        int rh = max(0,height(root->right));

        // Path passing through root that uses both children: root->val + lh + rh
        // Update global maximum path sum
        maxi = max(maxi, root->val + lh + rh);

        // Return the maximum sum for a path that starts at root and extends
        // downward to one side (used by parent's computation).
        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode* root) {
        height(root);
        return maxi;
    }
};