// https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> values;
        int maxCount(0);
        traverse(root, values, maxCount);
        
        vector<int> out;
        for (auto& kvp : values) {
            if (kvp.second == maxCount)
                out.push_back(kvp.first);
        }
        
        return out;
    }
    
    void traverse(TreeNode* root, unordered_map<int, int>& values, int& maxCount) {
        if (root == nullptr)
            return;
        
        if (++values[root->val] > maxCount)
            maxCount = values[root->val];
        
        traverse(root->left, values, maxCount);
        traverse(root->right, values, maxCount);
    }
};
