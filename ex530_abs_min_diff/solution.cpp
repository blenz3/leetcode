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
    // Copy each value into a vector and then compare
    //   - Runtime linear
    //   - Space linear
    int getMinimumDifference(TreeNode* root) {
       vector<int> values;
        traverse(root, values);
        
        int minDiff(INT_MAX);
        for (int i = 0; i < values.size() - 1; ++i) {
            int diff = values[i + 1] - values[i];
            minDiff = std::min(diff, minDiff);
        }
        
        return minDiff;
    }
    
    void traverse(TreeNode* root, vector<int>& out) {
        if (root == nullptr) {
            return;
        }
        
        
        traverse(root->left, out);
        out.push_back(root->val);
        traverse(root->right, out);
    }
};
