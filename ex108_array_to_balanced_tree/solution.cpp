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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // strategy is to start from the middle keep adding the middle from both the left and right
        return insert(0, nums.size() - 1, nums);
        
    }
    
    
    TreeNode* insert(int start, int end, const vector<int>& nums) {
        if (start > end)
            return nullptr;
        
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->right = insert(mid + 1, end, nums);
        node->left = insert(start, mid -1, nums);
        return node;
    }
};
