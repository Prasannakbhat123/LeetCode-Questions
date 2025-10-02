#include <iostream>
#include <vector>
#include <queue>

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
    // Compute maximum width of a binary tree. The idea is to assign an index to
    // each node as if the tree were a complete binary tree: for a node with index
    // `id`, left child -> 2*id + 1, right child -> 2*id + 2. The width of a level
    // is last_index - first_index + 1. We perform a BFS (level-order traversal)
    // storing (node, index) pairs.
    //
    // Notes on overflow: indices grow exponentially with depth. To avoid very large
    // numbers we normalize indices at each level by subtracting the minimum index
    // in that level (called `mini`), so `cur_id = original_id - mini`. We store
    // indices in unsigned long long to provide a large range.
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        // Queue stores node + its index (as if placed in a complete binary tree)
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();

            // Use the first index in this level as the baseline to normalize indices
            unsigned long long mini = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                // Normalize current id to avoid overflow: cur_id is small within the level
                unsigned long long cur_id = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;

                // Assign indices for children using the normalized id to keep numbers small
                if (node->left)  q.push({node->left,  2 * cur_id + 1});
                if (node->right) q.push({node->right, 2 * cur_id + 2});
            }

            // Width of current level = last - first + 1
            ans = max(ans, static_cast<int>(last - first + 1));
        }

        // Time complexity: O(N) visiting each node once.
        // Space complexity: O(W) where W is maximum width of the tree (queue size), plus O(1) for indices.
        return ans;
    }
};
