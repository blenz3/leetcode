class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right)  / 2;
            if (left + 1 == right) {
                break;
            }
            
            if (nums[mid] == nums[right]) {
                right--;
            } else if (nums[mid] == nums[left]) {
                left++;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else { 
                left = mid;
            }
        }
        
        return (nums[left] < nums[right]) ? nums[left] : nums[right];
    }
};
