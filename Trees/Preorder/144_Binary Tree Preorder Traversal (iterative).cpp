#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // Result vector to collect preorder sequence (Node -> Left -> Right)
        vector<int> ans;

        // Edge case: empty tree
        if (root == nullptr)
            return ans;

        // Use a stack to perform iterative preorder traversal.
        // Push root, then loop: pop, visit, push right then left.
        // Pushing right before left ensures left is processed first (LIFO).
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            // Visit current node
            ans.push_back(node->val);

            // Push right first so left is on top of the stack
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }

        // Time: O(N) — each node is visited once
        // Space: O(H) — stack size up to tree height (worst O(N))
        return ans;
    }
};