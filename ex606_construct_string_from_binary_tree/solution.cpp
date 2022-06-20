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
    string tree2str(TreeNode* root) {
        string s;
        traverse(root, s);
        return s;
    }
    
private:
    void traverse(TreeNode* root, string& s) {
        
        if (root == nullptr) {
            return;
        }

        s += std::to_string(root->val);
        
        if (root->left == nullptr && root->right != nullptr) {
            s.push_back('(');
            s.push_back(')');
        }
        
        if (root->left != nullptr) {
            s.push_back('(');    
            traverse(root->left, s);
            s.push_back(')');    
        }
        
        if (root->right != nullptr) {
            s.push_back('(');   
            traverse(root->right, s);
            s.push_back(')');    
        }
        
    }
};
