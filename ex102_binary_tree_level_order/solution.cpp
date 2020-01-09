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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> levels;
        accumulateLevels(root, levels, 0);
        return levels;
    }
    
private:
    void accumulateLevels(TreeNode* root, std::vector<std::vector<int>>& levels, int depth) {
        if (root == nullptr)
            return;
        
        if (depth >= levels.size()) {
            levels.push_back(std::vector<int>{});
        }
        
        accumulateLevels(root->left, levels, depth + 1);
        levels[depth].push_back(root->val);
        accumulateLevels(root->right, levels, depth + 1);
    }
};
