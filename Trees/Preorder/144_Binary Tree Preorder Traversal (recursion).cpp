#include <vector>
using namespace std;

//  Definition for a binary tree node.
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

        // Visit node first (preorder)
        ans.push_back(root->val);

        // Recurse left then right
        answer(root->left, ans);
        answer(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> ans;
        if (root == nullptr)
            return ans;
        answer(root, ans);
        return ans;
    }
};