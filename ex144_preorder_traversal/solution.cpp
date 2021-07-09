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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> values;
        preOrderTraversalRec(root, values);
        return values;
    }
private:
    void preOrderTraversalRec(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        
        nodes.push_back(root->val);
        preOrderTraversalRec(root->left, nodes);
        preOrderTraversalRec(root->right, nodes);
    }
};
