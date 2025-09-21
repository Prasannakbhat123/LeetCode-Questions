#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        // Result vector
        vector<int> ans;

        // Edge case
        if (root == nullptr) return ans;

        // Two-stack method:
        // Push root to st1. While st1 not empty: pop node, push it to st2,
        // then push left and right children to st1. Finally, popping st2
        // yields nodes in postorder (Left, Right, Node).
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            // Push left then right so that right is processed before left
            // when building st2; final pop of st2 gives Left->Right->Node
            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        while (!st2.empty()) {
            TreeNode* node = st2.top();
            ans.push_back(node->val);
            st2.pop();
        }

        // Time: O(N), Space: O(N)
        return ans;
    }
};