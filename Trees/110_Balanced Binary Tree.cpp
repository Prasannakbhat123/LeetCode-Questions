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
        // Base case: empty tree has depth 0
        if(root==NULL) return 0;

        // Compute depth of left and right subtrees recursively and
        // return the larger one plus 1 for the current node.
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        // An empty tree is balanced
        if(root==NULL) return true;

        // Compute heights of left and right subtrees
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);

        // If the height difference at this node is more than 1, it's unbalanced
        if(abs(lh-rh)>1) return false;

        // Otherwise, the tree is balanced iff both subtrees are balanced
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(!left || !right) return false;

        return true;
    }
};