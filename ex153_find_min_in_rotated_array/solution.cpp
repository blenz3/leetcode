class Solution {
public:
    
    // Binary search for the minimum value
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right)  / 2;
            if (left == right || left + 1 == right) {
                break;
            }
            
            if (nums[mid] < nums[right]) {
                right = mid;
            } else { 
                left = mid;
            }
        }
        
        return (nums[left] < nums[right]) ? nums[left] : nums[right];
    }
    
#if 0
    // Brute force - walk the array and find the minimum number (O(n) time, O(1) space)
    int findMin(vector<int>& nums) {
        int minValue = INT_MAX;
        for (int val : nums) {
            minValue = std::min(minValue, val);
        }
        
        return minValue;
    }
    
#endif
};
