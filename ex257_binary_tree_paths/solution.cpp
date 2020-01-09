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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<string> paths;
        if (root == nullptr)
            return paths;
        
        std::vector<int> currentPath;
        accumulateTreePaths(root, currentPath, paths);
        return paths;
    }
    
private:
    void accumulateTreePaths(TreeNode* root, std::vector<int>& currentPath, std::vector<std::string>& completePaths) {
        if (root == nullptr) {
            return;
        }
        
        // Add this value to the path
        currentPath.push_back(root->val);
        
        // If this is a leaf then add it to the complete paths
        if (root->left == nullptr && root->right == nullptr) {
            completePaths.push_back(createPathString(currentPath));
        } else { 
            accumulateTreePaths(root->left, currentPath, completePaths);
            accumulateTreePaths(root->right, currentPath, completePaths);
        }
        
        // Remove this one from the path
        currentPath.pop_back();
    }
    
    std::string createPathString(const std::vector<int>& path) {
        std::string s;
        for (auto value : path) {
            s += std::to_string(value) + "->";
        }
        
        return s.substr(0, s.length() - 2);
    }
};
