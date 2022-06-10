class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> out;
        generateSubsets(nums, 0, current, out);
        return out;
    }
    
public:
    void generateSubsets(const vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& sets) {
        if (index == nums.size()) {
            sets.push_back(current);
            return;
        }
        
        // Don't add this element 
        generateSubsets(nums, index + 1, current, sets);
        
        // Add this element
        current.push_back(nums[index]);
        generateSubsets(nums, index + 1, current, sets);
        current.pop_back();
        
    }
};
