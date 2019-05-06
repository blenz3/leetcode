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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
        {
            return false;
        }
        
        // The spec indicates that this must be a true leaf to be considered a proper path (
        // true leaf meaning no children)
        if (root->left == nullptr && root->right == nullptr)
        {
            return (root->val == sum);
        }
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);

    }

};