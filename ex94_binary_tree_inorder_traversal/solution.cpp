/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return vector<int>();
        
        auto node_values = inorderTraversal(root->left); 
        node_values.push_back(root->val);
        auto right_traverse = inorderTraversal(root->right);
        for (auto& element : right_traverse)
        {
            node_values.push_back(element);
        }
        
        return node_values;
        
    }
    
};