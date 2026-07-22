/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    bool isValidBST(TreeNode* node, int minVal, int maxVal) {
        if (!node) return true;
        if(node->val >= maxVal || node->val <= minVal) return false;
        return isValidBST(node->left, minVal, node->val) && isValidBST(node->right, node->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
