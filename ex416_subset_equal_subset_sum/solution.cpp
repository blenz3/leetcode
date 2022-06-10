// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        memoization.clear();
        
        // Any set less than 2 cannot be partitioned
        if (nums.size() < 2 ) {
            return false;
        }
        
        // Any sum that is not divisble by 2 cannot be partitioned
        int leftSum = 0, rightSum = rangeSum(nums, 0);
        if (rightSum % 2 != 0) {
            return false;
        }
        
        // Backtrack where we include or exclude each individual number from the left partition
        return attemptPartition(nums, 0, leftSum, rightSum);
    }
    
    inline int rangeSum(const vector<int>& nums, size_t startIdx) {
        int sum(0);
        for (int i = startIdx; i < nums.size(); ++i) {
            sum += nums[i];
        }
        return sum;
    }
    
private:
    unordered_set<int> memoization;
    
    // Recursively attempt to move values from the right partition to the left partition. Explores the space
    // using backtracking and ends up running in 2^n time where n is the number of numbers
    bool attemptPartition(const vector<int>& nums, size_t index, int leftSum, int rightSum) {
        // We've miraculously reached a point where the sums are equal
        if (leftSum == rightSum) {
            return true;
        }
        
        // We're only ever "reassigning" values from the right sum to the left sum so if the 
        // left partition has a greater sum than the right then we don't need to continue;
        if (index == nums.size() || leftSum > rightSum) {
            memoization.insert(rightSum);
            return false;
        }
        
        if (memoization.count(rightSum) != 0) {
            return false;
        }
        
        return (
            attemptPartition(nums, index + 1, leftSum + nums[index], rightSum - nums[index]) || 
            attemptPartition(nums, index + 1, leftSum, rightSum)
        );
    }
};
