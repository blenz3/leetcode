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
        auto bst = root;
        auto gst = copyTree(root);
        traverseForGstValues(gst, bst);
        
        return gst;
    }
    
    void traverseForGstValues(TreeNode* gst, TreeNode* bst_root)
    {
        if (gst == nullptr)
        {
            return;
        }
        
        gst->val = sumGreater(bst_root, gst->val);
        traverseForGstValues(gst->left, bst_root);
        traverseForGstValues(gst->right, bst_root);
    }
    
    TreeNode* copyTree(TreeNode* root)
    {
        if (root == nullptr)
            return root;
        
        auto node = new TreeNode(root->val);
        node->left = copyTree(root->left);
        node->right = copyTree(root->right);
        
        return node;
    }
    
    int sumGreater(TreeNode* root, int minimum_value)
    {
        if (root == nullptr)
            return 0;
        
        return ((root->val >= minimum_value) ? root->val : 0) + sumGreater(root->left, minimum_value) + sumGreater(root->right, minimum_value);
    }
};