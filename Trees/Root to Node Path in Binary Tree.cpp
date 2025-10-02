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
    // Helper function to get the path from root to the node with value x
    // Uses DFS and backtracking: push the current node, recurse into children,
    // and pop if the target is not found in the current branch.
    bool getPath(TreeNode *root, vector<int> &arr, int x) {
        if (!root)
            return false;

        arr.push_back(root->val);

        if (root->val == x)
            return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;

        arr.pop_back(); // backtrack when target not present in this subtree
        return false;
    }

    // Wrapper to return the path from A (root) to node with value B.
    // Complexity: Time O(N) to search the tree in the worst case; Space O(H) recursion stack plus O(H) for the path.
    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        getPath(A, arr, B);
        return arr;
    }
};
