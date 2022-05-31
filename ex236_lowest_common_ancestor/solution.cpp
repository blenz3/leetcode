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
    Solution() : result(nullptr) {}
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Nothing found
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        recurseTree(root, p, q);
        return result;
    }
    
    int recurseTree(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = recurseTree(root->left, p, q);
        int right = recurseTree(root->right, p, q);
        int mid = (root == p || root == q) ? 1 : 0;
        
        if (mid + left + right >= 2) {
            result = root;
        }
        
        return (mid + left + right > 0) ? 1 : 0;
    }
   
private:
    TreeNode* result;
};
