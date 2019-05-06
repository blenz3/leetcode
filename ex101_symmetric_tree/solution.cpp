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
    bool isSymmetric(TreeNode* root) 
    {
        return comparePath(root, root);
    }
    
    bool comparePath(TreeNode* a, TreeNode* b)
    {
        if (a == nullptr && b == nullptr)
        {
            return true;   
        }
        else if (a == nullptr || b == nullptr)
        {
            return false;
        }
        
        return (a->val == b->val) && comparePath(a->left, b->right) && comparePath(a->right, b->left);
        
    }
};