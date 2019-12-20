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
    TreeNode* insertIntoBST(TreeNode* root, int val) {        
        insert(root, val);
        return root;
    }
    
private:
    // Iterative version
    void insert(TreeNode* root, int val) {
        TreeNode* new_node = new TreeNode(val);
        
        while (true) {
            TreeNode*& next = (root->val < val) ? root->right : root->left;
            if (next == nullptr) {
                next = new_node;
                break;
            }
            
            root = next;
        }        
    }
    
#if 0
    // Recursive version
    void insert(TreeNode*& root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return;
        }
        
        if (root->val < val)
            insert(root->right, val);
        else
            insert(root->left, val);
    }
#endif
};
