class Solution {
public:

    // Cache find results in an array and then traverse the array to
    // gather missing ones - O(n) time, O(n) space
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        if (nums.empty())
            return nums;
        
        std::vector<bool> found_numbers(nums.size() + 1);
        std::fill(found_numbers.begin(), found_numbers.end(), false);
        
        for (auto& number : nums)
        {
            found_numbers[number] = true;
        }
        
        std::vector<int> missing;
        for (int i = 1; i < found_numbers.size(); ++i)
        {
            if (!found_numbers[i])
                missing.push_back(i);
        }
        
        return missing;
    }
#if 0
    // Insert into a hash set and check each number - O(n) time, O(n) space
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        std::unordered_set unique_numbers(nums.begin(), nums.end());
        
        std::vector<int> missing_numbers;
        int expected_number(1);
        for (int expected_number = 1; expected_number <= nums.size(); ++expected_number)
        {
            if (unique_numbers.count(expected_number) == 0)
            {
                missing_numbers.push_back(expected_number);
            }
        }
        
        return missing_numbers;
    }
#endif
};