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
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int max_depth(0);
        maxDiameter(root, max_depth);
        return max_depth - 1;
    }
    
private:
    int maxDiameter(TreeNode* root, int& max_depth)
    {
        if (root == nullptr)
            return 0;
        
        int left = maxDiameter(root->left, max_depth);
        int right = maxDiameter(root->right, max_depth);
        if (left + right + 1 > max_depth)
            max_depth = left + right + 1;
        
        return std::max(left, right) + 1;
    }

};