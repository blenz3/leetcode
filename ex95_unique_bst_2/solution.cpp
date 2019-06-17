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
    vector<TreeNode*> generateTrees(int n)
    {
        if (n <= 0)
        {
            return vector<TreeNode*>();
        }
        
        return generateTreeRange(1, n);
    }
    
    vector<TreeNode*> generateTreeRange(int begin, int end)
    {
        std::vector<TreeNode*> all_trees;
        if (begin > end) 
        {
            all_trees.push_back(nullptr);
            return all_trees;
        }
        
        for (int i = begin; i <= end; ++i)
        {
            auto left_trees = generateTreeRange(begin, i - 1);
            auto right_trees = generateTreeRange(i + 1, end);
            
            for (auto& l : left_trees)
            {
                for (auto& r : right_trees)
                {
                    auto new_tree = new TreeNode(i);
                    new_tree->left = l;
                    new_tree->right = r;
                    
                    all_trees.push_back(new_tree);
                }
            }
        }
        return all_trees;
        
    }
};