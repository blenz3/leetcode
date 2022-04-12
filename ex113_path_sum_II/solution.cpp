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
    // DFS from the start point and explore all nodes. It's not a search tree so we must explore them all
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> partials;
        vector<vector<int>> solutions;
        
        backtrack(root, 0, targetSum, partials, solutions);
        return solutions;
    }
    
    void backtrack(TreeNode* root, int sum, int target, vector<int>& partial, vector<vector<int>>& solutions) {
        // Nothing can be done with this nullptr
        if (root == nullptr) {
            return;
        }
        
        // Capture this node's attributes in the path
        sum += root->val;
        partial.push_back(root->val);
        
        // If we have reached a leaf do check if it matches the required sum 
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target)
                solutions.push_back(partial);
        } 
        
        backtrack(root->left, sum, target, partial, solutions);
        backtrack(root->right, sum, target, partial, solutions);
        partial.erase(--partial.end());
    }
};
