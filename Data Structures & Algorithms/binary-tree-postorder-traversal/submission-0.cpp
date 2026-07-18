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
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return result;
    }
private:
    void postorder(TreeNode* node) {
        if(!node) return;
        postorder(node->left);
        postorder(node->right);
        result.push_back(node->val);
    }
};