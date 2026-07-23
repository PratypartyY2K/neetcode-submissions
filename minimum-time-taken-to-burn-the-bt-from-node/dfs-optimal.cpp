#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    int maxTime = 0;

    // Returns {height, distanceToTarget}
    // distanceToTarget = -1 if target is not in this subtree
    pair<int, int> dfs(Node* node, int target) {
        if (node == nullptr)
            return {0, -1};

        auto [leftHeight, leftDist] = dfs(node->left, target);
        auto [rightHeight, rightDist] = dfs(node->right, target);

        int currHeight = 1 + max(leftHeight, rightHeight);

        // Case 1: Current node is the target
        if (node->val == target) {
            maxTime = max(maxTime, max(leftHeight, rightHeight));
            return {currHeight, 1};
        }

        // Case 2: Target is in left subtree
        if (leftDist != -1) {
            maxTime = max(maxTime, leftDist + rightHeight);
            return {currHeight, leftDist + 1};
        }

        // Case 3: Target is in right subtree
        if (rightDist != -1) {
            maxTime = max(maxTime, rightDist + leftHeight);
            return {currHeight, rightDist + 1};
        }

        // Target not present
        return {currHeight, -1};
    }

public:
    int minTimeToBurn(Node* root, int target) {
        maxTime = 0;
        dfs(root, target);
        return maxTime;
    }
};
