class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int expected_sum = (nums.size() * (nums.size() + 1)) / 2;
        int actual_sum(0);
        for (auto num : nums)
            actual_sum += num;
        
        return expected_sum - actual_sum;
    }
};