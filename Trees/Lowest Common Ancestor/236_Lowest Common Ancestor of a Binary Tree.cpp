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
    // Optimal recursive approach:
    // - If root is NULL, or equals p or q, return root (base cases).
    // - Recursively search left and right subtrees for p and q.
    // - If both sides return non-NULL, root is the LCA; otherwise return the non-NULL child.
    // This visits each node once (O(N) time) and uses O(H) recursion stack where H is tree height.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root; // base case: found p or q or reached end
        }

        // Search for p and q in left and right subtrees
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        // If both sides returned non-null, they each contain one of p/q -> root is LCA
        if (l == NULL) return r;
        else if (r == NULL) return l;
        else return root;
    }
};