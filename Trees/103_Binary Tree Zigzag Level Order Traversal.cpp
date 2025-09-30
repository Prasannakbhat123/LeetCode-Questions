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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Result vector where each inner vector holds values of one tree level
        vector<vector<int>> ans;

        // Edge case: empty tree -> return empty result
        if (root == NULL) return ans;

        // Use a queue to perform breadth-first search (BFS).
        // For each level we take the current queue size (number of nodes at this level),
        // then pop exactly that many nodes while pushing their children for the next level.
        // To implement zigzag order we write values into a pre-sized `level` vector at
        // computed indices instead of appending and reversing — this is more efficient.
        queue<TreeNode*> q;
        q.push(root);

        // Direction flag: true means fill left->right; false means fill right->left.
        bool isLeftToRight = true;

        while (!q.empty()) {
            int n = q.size();

            // Preallocate level vector with the number of nodes in this level.
            vector<int> level(n);

            // Process all nodes in the current level
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Determine index to place this node's value based on current direction.
                // If filling left->right place at i; if right->left place at (n - i - 1).
                int idx = isLeftToRight ? i : (n - i - 1);
                level[idx] = node->val;

                // Enqueue children for the next level (standard BFS behaviour)
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // After finishing this level, flip the direction for the next level
            isLeftToRight = !isLeftToRight;

            // Append the completed level to the answer
            ans.push_back(level);
        }

        // Time complexity: O(N) where N is the number of nodes (each visited once)
        // Space complexity: O(W) where W is the maximum width of the tree (queue + output storage)
        return ans;
    }
};