class Solution {
public:
    
    // Optimization 
    //  - Binary search where we check if mid is a peak.
    //  - If not a peak then keep searching left if lhs is bigger else rhs
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        if (isPeak(nums, left)) 
            return left;
        else if (isPeak(nums, right))
            return right;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (isPeak(nums, mid)) {
                return mid;
            } 
            
            int leftVal = (mid - 1 < 0) ? INT_MIN : nums[mid - 1];
            int rightVal = (mid + 1 >= nums.size()) ? INT_MIN : nums[mid + 1];
            if (leftVal < rightVal) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    inline bool isPeak(vector<int>& nums, int i) {
        return (
            (i == 0 || nums[i] > nums[i - 1]) &&
            (i == nums.size() - 1 || nums[i] > nums[i + 1])
        );
    }
    
#if 0
    // Brute force
    //  - Linear scan 
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if ((i == 0 || nums[i] > nums[i - 1]) &&
                (i == nums.size() - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }
                
        return -1;
    }
#endif
};
