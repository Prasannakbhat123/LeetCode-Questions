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
    // Helper: DFS that visits right subtree before left. We keep track of the current
    // level and compare it with ans.size(). When level == ans.size(), we are visiting
    // the first node at this depth (from the right), so we add it to the answer.
    void answer(TreeNode* root, int level, vector<int>& ans) {
        if (root == NULL) return;

        // If this is the first node we're visiting at this level, record it.
        if (level == (int)ans.size()) ans.push_back(root->val);

        // Recurse right first so that rightmost nodes are encountered before left ones.
        answer(root->right, level + 1, ans);
        answer(root->left, level + 1, ans);
    }

    // Time: O(N) visiting each node once. Space: O(H) recursion stack (H = height).
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        answer(root, 0, ans);
        return ans;
    }
};