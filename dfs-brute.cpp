#include <iostream>
#include <algorithm>
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

    // Returns height of the subtree
    int height(Node* node) {
        if (node == nullptr)
            return 0;

        return 1 + max(height(node->left), height(node->right));
    }

    // Returns:
    // -1 : target not present
    // >0 : distance from current node to target
    int solve(Node* node, int target) {
        if (node == nullptr)
            return -1;

        // Target found
        if (node->val == target) {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);

            maxTime = max(maxTime, max(leftHeight, rightHeight));

            return 1;
        }

        int leftDist = solve(node->left, target);
        int rightDist = solve(node->right, target);

        // Target is in left subtree
        if (leftDist != -1) {
            int rightHeight = height(node->right);

            maxTime = max(maxTime, leftDist + rightHeight);

            return leftDist + 1;
        }

        // Target is in right subtree
        if (rightDist != -1) {
            int leftHeight = height(node->left);

            maxTime = max(maxTime, rightDist + leftHeight);

            return rightDist + 1;
        }

        return -1;
    }

public:
    int minTimeToBurn(Node* root, int target) {
        maxTime = 0;
        solve(root, target);
        return maxTime;
    }
};
