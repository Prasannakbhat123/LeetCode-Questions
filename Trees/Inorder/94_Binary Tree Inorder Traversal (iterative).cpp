
#include <vector>
#include <stack>
using namespace std;

//   Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // Result vector to store inorder sequence
        vector<int> ans;

        // Edge case: empty tree
        if (root == nullptr)
            return ans;

        // Use a stack to simulate recursion. The idea:
        // - Go as left as possible, pushing nodes onto stack.
        // - When you reach a nullptr, pop the last node, visit it,
        //   then switch to its right child.
        // This yields Left -> Node -> Right ordering (inorder).
        TreeNode *node = root;
        stack<TreeNode *> st;

        // Loop invariant: either `node` is non-null (we can go left),
        // or stack is non-empty (there are nodes to visit). If both
        // are null/empty, traversal is complete.
        while (true)
        {
            if (node)
            {
                // Push current node and move left to continue visiting left subtree
                st.push(node);
                node = node->left;
            }
            else
            {
                // If node is null, we've reached the leftmost for the current path.
                // Pop from stack to visit the parent node, then explore its right subtree.
                if (st.empty())
                    break; // traversal finished
                node = st.top();
                st.pop();

                // Visit the node (inorder position)
                ans.push_back(node->val);

                // Now visit the right subtree
                node = node->right;
            }
        }

        // Complexity:
        // Time: O(N) — each node is pushed/popped at most once.
        // Space: O(H) — stack holds at most the tree height (worst-case O(N)).
        return ans;
    }
};