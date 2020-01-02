class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        size_t pivot = findPivot(nums);
        int lowerIndex = binarySearchRange(nums, pivot, nums.size() - 1, target);
        if (lowerIndex != -1) {
            return lowerIndex;
        }
        
        int upperIndex = binarySearchRange(nums, 0, pivot, target);
        if (upperIndex != -1) {
            return upperIndex;
        }
        
        return -1;
    }
    
private:
    size_t findPivot(const vector<int>& nums) {
        size_t left = 0, right = nums.size() - 1;
        while (left < right) {
            size_t mid = (left + right) / 2;
            if (mid == left)
                break;
            
            if (nums[mid] < nums[left]) {
                right = mid;       
            } else {
                left = mid;
            }
        }
        return (nums[left] < nums[right]) ? left : right;
    }
    
    int binarySearchRange(const vector<int>& nums, int left, int right, const int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return -1;
    }
};
