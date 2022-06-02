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
    // Strategy
    //   - Traverse the tree from the right to the left and keep a level map where we will fill in the first 
    //     node that we notice at that level
    vector<int> rightSideView(TreeNode* root) {
        vector<int> levels;
        traverse(root, 0, levels);
        return levels;
    }
    
private:
    void traverse(TreeNode* root, int currentLevel, vector<int>& levels) {
        if (root == nullptr)
            return;
        
        if (currentLevel >= levels.size()) {
            levels.push_back(root->val);
        }
        
        traverse(root->right, currentLevel + 1, levels);
        traverse(root->left, currentLevel + 1, levels);
    }
};
