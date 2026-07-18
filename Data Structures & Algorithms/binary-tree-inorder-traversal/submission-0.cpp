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
    vector<int> answer;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        visit(root);
        return answer;
    }

private:
    void visit(TreeNode* node) {
        if(!node) {
            return;
        }
        visit(node->left);
        answer.push_back(node->val);
        visit(node->right);
    }
};