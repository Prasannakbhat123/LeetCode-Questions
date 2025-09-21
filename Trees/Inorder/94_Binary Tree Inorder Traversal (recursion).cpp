
#include <vector>
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
    void answer(TreeNode *root, vector<int> &ans)
    {
        // Base case: empty subtree
        if (root == nullptr)
            return;

        // Recurse left (visit all left subtree nodes first)
        answer(root->left, ans);

        // Visit current node (inorder position)
        ans.push_back(root->val);

        // Recurse right
        answer(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        // Result vector
        vector<int> ans;

        // Edge case: empty tree
        if (root == nullptr)
            return ans;

        // Fill ans via helper recursive function
        answer(root, ans);
        return ans;
    }
};