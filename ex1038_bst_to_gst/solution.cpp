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
    TreeNode* bstToGst(TreeNode* root) 
    {
        if (root == nullptr)
            return nullptr;
        
        int count(0);
        in_order_traverse(root, count);
        return root;
    }
    
    void in_order_traverse(TreeNode* bst, int& current_count)
    {
        if (bst == nullptr)
        {
            return;
        }
        
        in_order_traverse(bst->right, current_count);
        current_count += bst->val;
        bst->val = current_count;
        
        in_order_traverse(bst->left, current_count);
    }
};