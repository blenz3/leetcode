class Solution {
public:
    // Fancy bit twiddling. We are going to bitwise xor every
    // value together which will nullify all the bits
    // except for those from the missing number
    int singleNumber(vector<int>& nums) {
        int num = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
        {
            num ^= nums[i];
        }
        
        return num;        
    }
    
    // Classic solution where we just throw counts into
    // a map and then look for the number with only 1 
    // observation
    int singleNumberWithMemory(vector<int>& nums) {
        map<int, int> number_counts;
        
        for (auto num : nums)
        {
            number_counts[num]++;
        }
        
        for (auto number_count : number_counts)
        {
            if (number_count.second == 1)
            {
                return number_count.first;
            }
        }
        
        return -1;    
    }
};