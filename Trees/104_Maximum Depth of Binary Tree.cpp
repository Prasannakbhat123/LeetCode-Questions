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
    int maxDepth(TreeNode* root) {
        // Base case: if the node is null, depth is 0
        if(root==NULL) return 0;

        // Recursively compute the depth of the left and right subtrees.
        // The depth of the current tree is 1 (for the current node) plus
        // the maximum of the depths of its subtrees.
        // This is a standard DFS recursion that visits each node once.
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};