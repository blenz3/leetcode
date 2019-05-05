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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // P is null xor q is null means that they are different
        // because one has more nodes than the other
        if ((p == nullptr) != (q == nullptr)) 
        {
            return false;
        }
        else if (p == nullptr && q == nullptr)
        {
            return true;
        }
        
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
};