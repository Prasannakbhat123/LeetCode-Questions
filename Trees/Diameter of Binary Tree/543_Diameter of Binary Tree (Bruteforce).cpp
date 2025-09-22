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
    int maxi=0;
    int maxDepth(TreeNode* root) {
        // Compute height (max depth) of tree rooted at `root`.
        // Base case: empty subtree has height 0.
        if(root==NULL) return 0;

        // Recursively compute heights of left and right subtrees and
        // add 1 for the current node.
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // Brute-force approach:
        // For each node, compute height of left and right subtrees (lh, rh).
        // The longest path that passes through this node is lh + rh (number of edges),
        // and we keep track of the maximum seen across all nodes in `maxi`.
        // To visit every node we recursively call diameterOfBinaryTree on children.

        // Base case: empty tree -> return current maximum
        if(root==NULL) return maxi;

        // Heights of left and right subtrees
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);

        // Update global maximum diameter (number of edges along the path)
        maxi=max(maxi,lh+rh);

        // Recur for children to consider paths through all nodes
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;
    }
};