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
    int sumNumbers(TreeNode* root) {
        return traverse(root, 0);
    }
    
    int traverse(TreeNode* root, int path) {
        if (root == nullptr) {
            return 0;
        }
        
        // Always increase by a power of 10 and just add our digit
        path *= 10;
        path += root->val;
        
        // This is a leaf so return path sum
        if (root->left == nullptr && root->right == nullptr) {
            return path;
        }
        
        int sum(0);
        sum += traverse(root->left, path);
        sum += traverse(root->right, path);
        return sum;
    }
};
