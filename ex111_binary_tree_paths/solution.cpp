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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int minimumDepth = INT_MAX;
        findMinimumDepth(root, 0, minimumDepth);
        return minimumDepth;
    }
    
private:
    void findMinimumDepth(TreeNode* root, int currentDepth, int& minimumDepth) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            minimumDepth = std::min(currentDepth + 1, minimumDepth);
        } else {
            findMinimumDepth(root->left, currentDepth + 1, minimumDepth);
            findMinimumDepth(root->right, currentDepth + 1, minimumDepth);
        }
    }
};
