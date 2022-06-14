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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> levels;
        vector<size_t> levelCounts;
        traverse(root, 0, levels, levelCounts);
        
        for (int i = 0; i < levels.size(); ++i) {
            levels[i] /= levelCounts[i];
        }
        
        return levels;
    }
    
    
private:
    
    void traverse(TreeNode* root, size_t level, vector<double>& levels, vector<size_t>& levelCounts) {
        if (root == nullptr)
            return;
        
        if (level == levels.size()) {
            levels.push_back(static_cast<double>(root->val));
            levelCounts.push_back(1);
        } else {
            levels[level] += static_cast<double>(root->val);
            levelCounts[level]++;
        }
        
        traverse(root->left, level + 1, levels, levelCounts);
        traverse(root->right, level + 1, levels, levelCounts);   
    }
};
