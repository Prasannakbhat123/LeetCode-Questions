#include <iostream>
#include <vector>
using namespace std;

// Simple binary tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
private:
    // Helper: return true if the node is a leaf (no children)
    bool isLeaf(Node* node) {
        // A null pointer is not considered a leaf here; callers check for null where needed.
        return node && !node->left && !node->right;
    }

    // Add the left boundary nodes (excluding leaves) top-down.
    // We start from root->left and keep following left when possible,
    // otherwise follow right. We skip leaf nodes because they will be
    // added by addLeaves (to avoid duplicates).
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            // Prefer left child; if not present, go to right child.
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }

    // Add the right boundary nodes (excluding leaves) bottom-up.
    // We traverse similarly to the left boundary but collect values in a
    // temporary vector and append them in reverse so the final order is
    // from bottom to top as required by boundary traversal.
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            // Prefer right child; if not present, go to left child.
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        // Append collected right-boundary nodes in reverse order so that
        // traversal goes from bottom -> top for the right boundary.
        for (int i = (int)tmp.size() - 1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }

    // Add all leaf nodes in left-to-right order using DFS.
    // This will collect leaves from the left subtree first then right subtree,
    // which ensures the correct order for boundary traversal.
    void addLeaves(Node* root, vector<int>& res) {
        if (!root) return;
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

public:
    // Returns the boundary traversal of the binary tree as a vector of values.
    // Boundary traversal order:
    // 1) Root (if not a leaf)
    // 2) Left boundary (excluding leaves) from top to bottom
    // 3) All leaves from left to right
    // 4) Right boundary (excluding leaves) from bottom to top
    // The implementation avoids duplicates by skipping leaves in the boundary helpers.
    vector<int> printBoundary(Node *root) {
        vector<int> res;
        if (!root) return res; // Empty tree -> empty boundary

        // Root should be included unless it is the only node and thus a leaf
        if (!isLeaf(root))
            res.push_back(root->data);

        // Add left boundary (top-down, excluding leaves)
        addLeftBoundary(root, res);

        // Add all leaves (left-to-right)
        addLeaves(root, res);

        // Add right boundary (bottom-up, excluding leaves)
        addRightBoundary(root, res);

        return res;
    }
};

/*
Complexity:
- Time: O(N) where N is number of nodes, because each node is visited a constant
  number of times across the helpers (left/right boundary traversal + leaf DFS).
- Space: O(H) recursion stack for addLeaves (worst-case H = N for skewed tree),
  plus O(W) for temporary storage where W is the width (but overall output size is O(N)).

Notes / Edge cases:
- Single-node tree: the root is a leaf; the algorithm will not duplicate it because
  we only push root value when it is not a leaf, and addLeaves will add it once.
- Trees where some nodes have only one child: boundary helpers prefer the side that
  keeps the traversal along the outside edge (left-boundary prefers left child, right-boundary prefers right child).
*/
