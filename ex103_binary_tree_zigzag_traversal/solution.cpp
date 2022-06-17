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

    // Naive solution
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        traverse(root, levels, 0);
        for (int i = 1; i < levels.size(); ++i) {
            if (i % 2 == 1) {
                std::reverse(levels[i].begin(), levels[i].end());
            }
        }
        return levels;
    }
    
private:
    void traverse(TreeNode* node, vector<vector<int>>& levels, size_t depth) {
        if (node == nullptr)
            return;
        
        if (depth == levels.size()) {
            levels.push_back(std::vector<int>{node->val});
        } else {
            levels[depth].push_back(node->val);
        }
        
        traverse(node->left, levels, depth + 1);
        traverse(node->right, levels, depth + 1);
    }
};
