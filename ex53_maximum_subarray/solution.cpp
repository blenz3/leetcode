class Solution {
public:
    
    // brute force
    int maxSubArray(vector<int>& nums) {
        int current_sum(0), max_sum(0);
        current_sum = max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            current_sum = std::max(nums[i], current_sum + nums[i]);
            max_sum = std::max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};