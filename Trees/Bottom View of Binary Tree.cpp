#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
//   Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    // Bottom view: for each horizontal distance (column) we want the node that is
    // visible from the bottom — i.e., the last node encountered at that column
    // when traversing level-by-level (BFS). A BFS ensures we see nodes in increasing
    // depth order; updating the map with the current node's data will leave the
    // deepest node's value for that horizontal distance.
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        // Map horizontal distance -> node value. We overwrite the value when a deeper
        // node at the same horizontal distance is encountered during BFS.
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0}); // root has horizontal distance 0

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            Node* node = it.first;
            int line = it.second; // horizontal distance

            // Overwrite map entry for this horizontal distance. Because BFS visits
            // nodes level-by-level, later overwrites correspond to deeper nodes.
            mpp[line] = node->data;

            if (node->left)  q.push({node->left,  line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        // Collect results from leftmost column to rightmost
        for (auto &p : mpp) ans.push_back(p.second);
        return ans;
    }
};
