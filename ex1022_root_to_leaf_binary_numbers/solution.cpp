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
    int sumRootToLeaf(TreeNode* root) {
        int path(0), sum(0);
        traverse(root, path, sum);
        return sum;
    }
    
    void traverse(TreeNode* root, int path, int& sum) {
        if (root == nullptr) {
            return;
        }
        
        path <<= 1;
        path |= root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            sum += path;
            return;
        } 
        
        traverse(root->left, path, sum);
        traverse(root->right, path, sum);
        
        
    }
};
