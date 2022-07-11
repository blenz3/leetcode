class Solution {
public:
    
    // Approach 2: Capture values in hashset and be smarter
    int longestConsecutive(vector<int>& nums) {
        // Copy all numbers into hashmap where we flag each value as visited or not
        unordered_map<int, bool> numbers;
        for (auto num : nums) {
            numbers[num] = false;
        }
        
        // For each value in nums we then will check for adjacent values and update visitation
        // flags. We will only ever visit each number once 
        int maxLength(0);
        for (auto num : nums) {
            int consecutive(1);
            
            // Check if we've already evaluated this number
            auto findIt = numbers.find(num);
            if (findIt->second) {
                continue;
            }
                
            findIt->second = true;
            
            // Check smaller numbers
            auto smaller = num - 1;
            findIt = numbers.find(smaller);
            while (findIt != numbers.end()) {
                ++consecutive;
                findIt->second = true;
                findIt = numbers.find(--smaller);
            }
            
            // Check larger numbers
            ++num;
            findIt = numbers.find(num);
            while (findIt != numbers.end()) {
                ++consecutive;
                findIt->second = true;
                findIt = numbers.find(++num);
            }
            
            maxLength = std::max(maxLength, consecutive);
        }
        
        return maxLength;
    }
    
#if 0
    // Approach 1: Sort and walk the array
    //  - Runtime nlgn
    //  - Space constant
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        std::sort(nums.begin(), nums.end());
        
        int consecutive(1), maxLength(1), prevElement = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (prevElement == nums[i]) {
                // no-op
                continue;
            } 
            
            if (prevElement + 1 != nums[i]) {
                maxLength = std::max(maxLength, consecutive);
                consecutive = 1;
            } else {
                ++consecutive;
            }
            
            prevElement = nums[i];
        }
        
        maxLength = std::max(maxLength, consecutive);
        
        return maxLength;
        
    }
#endif
};
