class Solution {
public:
    int64_t twoSumClosest(vector<int>& nums, int begin, int end, int target)
    {
        int64_t closest_sum(INT_MAX);
        while (end > begin)
        {
            const int64_t current_sum = nums[begin] + nums[end];
            if (abs(current_sum - target)  < abs(closest_sum - target))
            {
                closest_sum = current_sum;
            }
            
            if (current_sum > target)
            {
                end--;
            }
            else 
            {
                begin++;
            }
        }
        
        return closest_sum;
    }
    
    int threeSumClosest(vector<int>& nums, int target) 
    {
        std::sort(nums.begin(), nums.end());
        
        int64_t closest_sum(INT_MAX);
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int64_t best_two_sum = twoSumClosest(nums, i + 1, nums.size() - 1, target - nums[i]);
            if (abs(best_two_sum + nums[i] - target) < abs(closest_sum - target))
                closest_sum = best_two_sum + nums[i];
            
        }
        
        return closest_sum;
    }
};