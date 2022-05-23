class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // strategy is to accumulate across the array in a single pass
        int currentSum(0), maxSum(0);
        for (auto val : nums) {
            if (val == 0) {
                currentSum = 0;
            } else {
                currentSum += val;
                maxSum = std::max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};
