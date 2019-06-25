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
    int maxPathSum(TreeNode* root)
    {
        int max_path(INT_MIN);
        maxPath(root, max_path);
        return max_path;
    }
            
private:
    int maxPath(TreeNode* root, int& max_path)
    {
        if (root == nullptr)
            return 0;
        
        int value = root->val;
        int left_max = maxPath(root->left, max_path);
        int right_max = maxPath(root->right, max_path);
        
        if (left_max > 0)
            value += left_max;
        
        if (right_max > 0)
            value += right_max;
        
        max_path = std::max(max_path, value);
        int out_path = std::max(left_max, right_max);
        if (out_path > 0)
        {
            return root->val + out_path;
        }
        else
        {
            return root->val;
        }
    }
};