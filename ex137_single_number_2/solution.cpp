class Solution {
public:
    // Sort the numbers and just see if there are three of each
    int singleNumber(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        
        
        int i = 1, count(1), previous(nums[0]);
        while (i < nums.size())
        {
            // we've reached 3 so reset
            if (count == 3)
            {
                previous = nums[i];
                count = 0;   
            }
            
            if (previous != nums[i])
                return previous;
            
            ++count;
            ++i;
        }
        
        if (count != 3)
            return previous;
        
        return INT_MAX;

    }
    
#if 0
    // Use a hash table to store the counts. Linear space, linear time
    int singleNumber(vector<int>& nums)
    {
        std::unordered_map<int, int> counts;
        for (auto& num : nums)
        {
            counts[num]++;
        }
        
        for (auto& kvp : counts)
        {
            if (kvp.second != 3)
                return kvp.first;
        }
        
        return -1;
    }
#endif
};