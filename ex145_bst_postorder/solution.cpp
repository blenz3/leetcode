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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> values;
        traverse(root, values);
        return values;
        
    }
    
private:
    void traverse(TreeNode* root, vector<int>& values) {
        if (root == nullptr)
            return;
        
        traverse(root->left, values);
        traverse(root->right, values);
        values.push_back(root->val);
    }
};
