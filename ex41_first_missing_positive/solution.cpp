class Solution {
public:
    
    // Get rid of impossible values and use the MSB of the integer in the output as an existence
    // indicator for the actual value
    int firstMissingPositive(vector<int>& nums)
    {
        // If 1 doesn't exist then blow it away
        if (nums.end() == std::find(nums.begin(), nums.end(), 1))
            return 1;
        
        // If there is only one element then it's two
        if (nums.size() == 1)
            return 2;
        
        // Blow away all the impossible values
        for (auto& num : nums)
        {
            if (num < 1 || num > nums.size())
                num = 1;
        }
        
        // Sign all of the existing values
        for (auto& num : nums)
        {
            if (nums[abs(num) - 1] < 0) // already been found
                continue;
            
            nums[abs(num) - 1] *= -1;
        }
        
        // Find the first missing one
        int missing(1);
        for (; missing <= nums.size(); ++missing)
        {
            if (nums[missing - 1] > 0)
                break;
        }
        
        return missing;
    }
    
#if 0
    // Use a hashmap to store all the positive numbers and then look them up from 1..N + 1
    int firstMissingPositive(vector<int>& nums) 
    {
        std::unordered_set<int> positive_numbers;
        for (auto& num : nums)
        {
            if (num >= 1)
                positive_numbers.insert(num);
        }
        for (int missing_number_candidate = 1; missing_number_candidate <= nums.size() + 1; ++missing_number_candidate)
        {
            auto find_it = positive_numbers.find(missing_number_candidate);
            if (find_it == positive_numbers.end())
                return missing_number_candidate;
        }
        
        return -1;
    }
 
    // Use a hashmap to store all the positive numbers and then look them up from 1..N + 1
    int firstMissingPositive(vector<int>& nums) 
    {
        std::unordered_set<int> positive_numbers;
        for (auto& num : nums)
        {
            if (num >= 1)
                positive_numbers.insert(num);
        }
        for (int missing_number_candidate = 1; missing_number_candidate <= nums.size() + 1; ++missing_number_candidate)
        {
            auto find_it = positive_numbers.find(missing_number_candidate);
            if (find_it == positive_numbers.end())
                return missing_number_candidate;
        }
        
        return -1;
    }

    // Brute force. For each number from 1..N + 1 see if it exists in the input. If it doesn't then return it. Quadratic time, linear space
    int firstMissingPositive(vector<int>& nums) 
    {
        for (int missing_number_candidate = 1; missing_number_candidate <= nums.size() + 1; ++missing_number_candidate)
        {
            auto find_it = std::find(nums.begin(), nums.end(), missing_number_candidate);
            if (find_it == nums.end())
                return missing_number_candidate;
        }
        
        return -1;
    }
#endif
};