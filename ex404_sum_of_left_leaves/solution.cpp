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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return sumByLeafType(root, false);
        
    }
    
    int sumByLeafType(TreeNode* root, bool is_left) {
        if (root == nullptr)
            return 0;
        
        if (is_left && root->left == nullptr && root->right == nullptr)
        {
            return root->val;            
        }
        else
        {
            return sumByLeafType(root->left, true) + sumByLeafType(root->right, false);
        }
    }
};