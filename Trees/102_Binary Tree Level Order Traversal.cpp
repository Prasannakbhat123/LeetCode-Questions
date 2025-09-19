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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Result vector where each inner vector holds values of one tree level
        vector<vector<int>> ans;

        // Edge case: empty tree -> return empty result
        if (root == NULL) return ans;

        // We'll use a queue to perform breadth-first search (BFS).
        // The queue stores nodes of the current frontier. For each level
        // we take the current queue size (number of nodes at this level),
        // then pop exactly that many nodes while pushing their children.
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // Number of nodes in the current level
            int n = q.size();

            // Collector for values in this level
            vector<int> level;

            // Process all nodes for this level
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // Push children into the queue for the next level
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);

                // Record the current node's value
                level.push_back(temp->val);
            }

            // Append the completed level to the answer
            ans.push_back(level);
        }

        // Time complexity: O(N) where N is number of nodes (each node visited once)
        // Space complexity: O(W) where W is the maximum width of the tree (queue + output storage)
        return ans;
    }
};