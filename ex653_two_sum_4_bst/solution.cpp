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
    bool findTarget(TreeNode* root, int k)
    {
        std::vector<int> values;
        getValues(root, values);
        
        int left(0), right(values.size() - 1);
        while (left < right)
        {
            const int current_sum = values[left] + values[right];
            if (current_sum == k)
            {
                return true;
            }

            if (current_sum > k)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
        
        return false;
    }
    
    void getValues(TreeNode* root, std::vector<int>& values)
    {
        if (root == nullptr)
            return;
        
        getValues(root->left, values);
        values.push_back(root->val);
        getValues(root->right, values);
        
    }
};