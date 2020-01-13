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
    
    // Scoot nodes from the left to the right in place
    // (O(n) time, O(1) space)
    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
            
        
        while (root) {
            if (root->left) {
                TreeNode* lastNodeOnTheRight = root->left;
                while (lastNodeOnTheRight->right != nullptr)
                    lastNodeOnTheRight = lastNodeOnTheRight->right;
                
                lastNodeOnTheRight->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            
            root = root->right;
        }
    }
    
#if 0
    // Copy all nodes into a list in-order and then reattach them all 
    // (O(n) time, O(n) space)
    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
            
        std::vector<TreeNode*> nodes;
        accumulateNodes(root, nodes);
        
        for (int i = 1; i < nodes.size(); ++i) {
            root->right = nodes[i];
            root = root->right;
        }
    }
    
private:
    void accumulateNodes(TreeNode* root, std::vector<TreeNode*>& nodes) {
        if (root == nullptr) {
            return;
        }
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = root->right = nullptr;
        nodes.push_back(root);
        
        accumulateNodes(left, nodes);
        accumulateNodes(right, nodes);
        
    }
#endif
};
