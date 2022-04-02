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
    int closestValue(TreeNode* root, double target) {
        int closest(INT_MAX);
        traverse(root, target, closest);
        return closest;
        
    }
    
private:
    void traverse(TreeNode* root, double target, int& closest) {
        if (root == nullptr) {
            return;
        }
        
        if (::fabs(root->val - target) < ::fabs(closest - target)) 
            closest = root->val;
        
        if (target < root->val) {
            traverse(root->left, target, closest);    
        } else {
            traverse(root->right, target, closest);    
        }
    }
};
