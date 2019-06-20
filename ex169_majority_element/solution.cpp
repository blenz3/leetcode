class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        std::unordered_map<int, size_t> num_counts;
        for (auto& num : nums)
        {
            num_counts[num]++;
            
        }
        
        for (auto& kvp : num_counts)
        {
            if (kvp.second > (nums.size() / 2))
                return kvp.first;
        }
        
        return INT_MIN;
    }
    
};