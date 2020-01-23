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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
    
#if 0
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr) {
            return nullptr;
        }
        
        return findLowestCommonAncestor(root, p, q);
    }
    
private:
    
    TreeNode* findLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* lca = nullptr;
        if (root == nullptr) {
            return nullptr;
        }
        
        bool nodesInSubtree = inSubtree(root, p) && inSubtree(root, q);
        if (!nodesInSubtree) {
            return lca;
        } 
            
        lca = root;
        TreeNode* left = findLowestCommonAncestor(root->left, p, q);
        lca = (left == nullptr) ? lca : left;
        
        TreeNode* right = findLowestCommonAncestor(root->right, p, q);
        lca = (right == nullptr) ? lca : right;
        
        return lca;
    }
    
    bool inSubtree(TreeNode* root, TreeNode* target) {
        if (root == nullptr) {
            return false;
        } else if (root == target) {
            return true;
        } 
        
        if (root->val > target->val) {
            return inSubtree(root->left, target);
        } else {
            return inSubtree(root->right, target);
        }
    }
#endif
};
