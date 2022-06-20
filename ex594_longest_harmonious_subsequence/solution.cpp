class Solution {
public:
    // Optimize by sorting
    //   - nlgn + n
    //   - constant space
    int findLHS(vector<int>& nums) {
        
        // Sort
        std::sort(nums.begin(), nums.end());
        
        
        // Walk the right pointer until we break the invariant that left + right <= 1
        // Then collapse the left ptr until the invariant is maintained
        int startIndex = 0, endIndex = 0, maxLength = 0;
        while (endIndex < nums.size()) {
            if (nums[endIndex] - nums[startIndex] <= 1) {
                ++endIndex;
                continue;
            }
            
            // We've broken the invariant so let's capture the best result so far
            if (nums[endIndex - 1] - nums[startIndex] == 1) {
                maxLength = std::max(maxLength, endIndex - startIndex);
            }

            // Move the left pointer forward until we're back in business
            while (nums[endIndex] - nums[startIndex] > 1) {
                startIndex++;
            }
        }
        
        // Handle the case where we walk the edge of the numbers without 
        // being interrupted
        if (nums[endIndex - 1] - nums[startIndex] == 1) {
            // printf("edge end %d start %d\n", endIndex, startIndex);
            maxLength = std::max(maxLength, endIndex - startIndex);
        }
            
        
        return maxLength;
    }
    
    
#if 0
    // Brute force
    //   - Quadratic time 
    //   - const space
    int findLHS(vector<int>& nums) {
        
        // For each element we get the count of elements equal or 1 greater and
        // the ocunt equal or 1 smaller. The greater of these counts is capture
        int maxLength = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            int minusCount(0), plusCount(0);
            bool minusValid(false), plusValid(false);
            for (int j = 0; j < nums.size(); ++j) {
                int base = nums[i], current = nums[j];
                if (current == base) {
                    minusCount++;
                    plusCount++;
                } else if (current < base && base - current <= 1) {
                    minusCount++;
                    minusValid = true;
                } else if (current > base && current - base <= 1) {
                    plusCount++;
                    plusValid = true;
                }
            }
            
            minusCount = (minusValid) ? minusCount : 0;
            plusCount = (plusValid) ? plusCount : 0;
            maxLength = std::max(maxLength, std::max(plusCount, minusCount));
        }
        return maxLength;
    }
#endif
};
