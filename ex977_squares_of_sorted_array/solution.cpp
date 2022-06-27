class Solution {
public:
    // Aproach 2
    //  - Keep a count of negative numbers
    //  - Square all numbers
    //  - Create output array.
    //  - Merge the negative and positive squares
    //  - Runtime n space n
    vector<int> sortedSquares(vector<int>& nums) {
        // Count negative numbers
        int lastNegativeIndex = -1; 
        for (int i = 0; i < nums.size(); ++i) {
            lastNegativeIndex = (nums[i] < 0) ? i : lastNegativeIndex;
            nums[i] *= nums[i];
        }
        
        int firstPositiveIndex = lastNegativeIndex + 1;
        vector<int> out(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            // Get the last negative and negative poasitive and compare them
            int negative = (lastNegativeIndex != -1) ? nums[lastNegativeIndex] : INT_MAX;
            int positive = (firstPositiveIndex != nums.size()) ? nums[firstPositiveIndex] : INT_MAX;
            if (negative < positive) {
                out[i] = negative;
                lastNegativeIndex--;
            } else {
                out[i] = positive;
                firstPositiveIndex++;
            }
        }
        return out;
    }
    
#if 0
    // Approach 1: Square & sort. time nlgn, space 1
    vector<int> sortedSquares(vector<int>& nums) {
        for (auto& num : nums) 
            num *= num;
        std::sort(nums.begin(), nums.end());
        return nums;
    }
#endif
    
};
