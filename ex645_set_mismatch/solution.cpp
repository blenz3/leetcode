class Solution {
public:
    
    // Cache each count into a separate array and then iterate it to find the missing number (O(n) time, O(n) space)
    vector<int> findErrorNums(vector<int>& nums) {
        std::vector<int> counts(nums.size(), 0);
        for (auto num : nums) {
            counts[num - 1]++;
        }
        
        int missing(-1), duplicated(-1);
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] == 0) {
                missing = i + 1;
            } else if (counts[i] > 1) {
                duplicated = i + 1;
            }
        }
        
        return std::vector<int>{duplicated, missing};
    }
    
#if 0
    // Cache each count from 1 -> n and find which one is missing and which one
    // is duplicated (O(n) time, O(n) space)
    vector<int> findErrorNums(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }
        
        int missing, duplicated;
        for (int i = 0; i < nums.size(); ++i) {
            if (counts[i + 1] == 0) 
                missing = i + 1;
            
            if (counts[i + 1] > 1)
                duplicated = i + 1;
        }
        
        return std::vector<int>{duplicated, missing};
    }
#endif
};
