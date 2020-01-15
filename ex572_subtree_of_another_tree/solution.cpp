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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr || t == nullptr) {
            return false;
        }
        
        std::vector<TreeNode*> commonPoints;
        findNodes(s, t->val, commonPoints);
        for (auto commonPoint : commonPoints) {
            if (compareSubtrees(commonPoint, t)) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    void findNodes(TreeNode* s, int val, std::vector<TreeNode*>& nodes) {
        if (s == nullptr) {
            return;
        }
        
        if (s->val == val) {
            nodes.push_back(s);
        } 
        
        findNodes(s->left, val, nodes);
        findNodes(s->right, val, nodes);
    }
    
    bool compareSubtrees(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) {
            return true;   
        } else if ((a == nullptr) != (b == nullptr)) {
            return false;
        }
        
        if (a->val != b->val) {
            return false;
        }
        
        return compareSubtrees(a->left, b->left) && compareSubtrees(a->right, b->right);
        
        
    }
};
