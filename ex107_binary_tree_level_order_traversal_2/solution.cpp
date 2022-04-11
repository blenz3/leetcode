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
    
     // bfs
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int depth = maxDepth(root, 0);
        vector<vector<int>> levels(depth, vector<int>{});
        
        if (root == nullptr) {
            return levels;    
        }
        
        queue<pair<TreeNode* /*root*/, int /*depth*/>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto top = q.front();
            if (top.first->left != nullptr) 
                q.push(make_pair(top.first->left, top.second + 1));
            
            if (top.first->right != nullptr)
                q.push(make_pair(top.first->right, top.second + 1));
            
            levels[levels.size() - top.second - 1].push_back(top.first->val);
            q.pop();
        }
        
        return levels;
    }
    
    int maxDepth(TreeNode* root, int depth) {
        if (root == nullptr)
            return depth;
        
        return std::max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
    }
    
    
#if 0
    // Capture results in the proper order
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = maxDepth(root, 0);
        vector<vector<int>> levels(depth, vector<int>{});
        traverse(root, 0, levels);
        
        return levels;
    }
    
    int maxDepth(TreeNode* root, int depth) {
        if (root == nullptr)
            return depth;
        
        return std::max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
    }
    
    void traverse(TreeNode* root, int level, vector<vector<int>>& levels) {
        if (root == nullptr) {
            return;
        }
                
        levels[levels.size() - level - 1].push_back(root->val);
        
        traverse(root->left, level + 1, levels);
        traverse(root->right, level + 1, levels);
    }
#endif
    
#if 0
    // Capture results in level order and then reverse
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levels;
        traverse(root, 0, levels);
        
        std::reverse(levels.begin(), levels.end());
        return levels;
    }
    
    void traverse(TreeNode* root, int level, vector<vector<int>>& levels) {
        if (root == nullptr) {
            return;
        }
        
        if (level + 1 > levels.size())
            levels.push_back({});
        
        levels[level].push_back(root->val);
        
        traverse(root->left, level + 1, levels);
        traverse(root->right, level + 1, levels);
    }
#endif
};
