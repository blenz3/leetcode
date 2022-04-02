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
    //   - Find min height and max height and compare
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        traverse(root, 0, balanced);
        return balanced;
    }

    int traverse(const TreeNode* root, const int depth, bool& balanced) {
        if (root == nullptr || !balanced) {
            return depth;
        }
        
        int leftHeight = traverse(root->left, depth + 1, balanced);
        int rightHeight = traverse(root->right, depth + 1, balanced);
        if (::abs(leftHeight - rightHeight) > 1)
            balanced = false;
        
        return max(leftHeight, rightHeight);
    }
};
