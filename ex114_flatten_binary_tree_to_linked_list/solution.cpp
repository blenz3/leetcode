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
};
