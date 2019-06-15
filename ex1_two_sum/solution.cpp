class Solution
{
public:
         // Optimized - use hash table and check if the complement exists. Linear runtime, linear space
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            std::unordered_map<int, int> observed_numbers;
            for (int i = 0; i < nums.size(); ++i)
            {
                auto find_it = observed_numbers.find(target - nums[i]);
                if (find_it != observed_numbers.end())
                {
                    return {find_it->second, i};
                }
                else
                {
                    observed_numbers[nums[i]] = i;
                }
            }
            
            return {-1, -1};

        }
    
#if 0
        // Brute force (quadratic runtime, constant space) just searches all pairs of elements and returns when the sum matches
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
                int lower_index(-1), upper_index(-1);
                for (int i = 0; i < nums.size(); ++i) {
                        for (int j = i + 1; j < nums.size(); ++j) {
                             if (nums[i] + nums[j] == target) {
                                lower_index = i;
                                upper_index = j;
                             }
                        }
                }
                return { lower_index, upper_index };
        }
#endif

};