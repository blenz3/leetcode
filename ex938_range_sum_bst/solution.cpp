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
    int rangeSumBSTNaive(TreeNode* root, int L, int R) {
    
        // Base case - we've evaluated to a nullptr
        if (root == nullptr)
            return 0;
        
        return ((root->val >= L && root->val <= R) ? root->val : 0) + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
    
        // Base case - we've evaluated to a nullptr
        if (root == nullptr)
            return 0;
        
        
        if (root->val < L)
        {
            return rangeSumBST(root->right, L, R);
        }
        else if (root->val > R)
        {
            return rangeSumBST(root->left, L, R);
        }
        else
        {
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
    }
};