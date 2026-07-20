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
    void recursion(TreeNode* node, vector<int> &res, int level) {
        if(!node) return;
        if(level == res.size())
            res.push_back(node->val);
        // reverse pre-order traversal
        recursion(node->right, res, level+1);
        recursion(node->left, res, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        recursion(root, result, 0);
        return result;
    }
};
