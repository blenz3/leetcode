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
    int pathSum(TreeNode* root, int targetSum) {
        int64_t totalPaths = 0;
        traverse(root, targetSum, totalPaths);
        return totalPaths;
    }
    
private:        
    // Traverse the tree and count paths from each node keeping a running total
    void traverse(TreeNode* root, int64_t targetSum, int64_t& totalPaths) {
        if (root == nullptr) {
            return;
        }
        
        totalPaths += countPaths(root, 0, targetSum);
        traverse(root->left, targetSum, totalPaths);
        traverse(root->right, targetSum, totalPaths);
    }
    
    // Count all paths from a specific node
    int countPaths(TreeNode* root, int64_t sum, int64_t targetSum) {
        if (root == nullptr) 
            return 0;
        
        int total(0);
        if (root->val + sum == targetSum) {
            total++;
        }
        
        total += countPaths(root->left, sum + root->val, targetSum);
        total += countPaths(root->right, sum + root->val, targetSum);
        
        return total;
    }
};
