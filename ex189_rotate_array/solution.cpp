class Solution {
public:
    
     // Reverse the entire list and then reverse in sections around the rotation mark (O(n) time, O(1) space) 
     void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k == nums.size() || k == 0) {
            return;
        }
        
        k %= nums.size();
         
         // Reverse the entire list
         reverseRange(nums, 0, nums.size() - 1);
         
         // Reverse the first portion of the list
         reverseRange(nums, 0, k - 1);
         
         // Reverse the second half
         reverseRange(nums, k, nums.size() - 1);
    }
    
private:
    void reverseRange(vector<int>& nums, int startIndex, int endIndex) {
        while (startIndex <= endIndex) {
            auto tmp = nums[startIndex];
            nums[startIndex] = nums[endIndex];
            nums[endIndex] = tmp;
            startIndex++;
            endIndex--;
        }
    }
    
#if 0
    // Simple solution with a copy of the array (O(n) time, O(n) space)
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k == nums.size() || k == 0) {
            return;
        }
        
        k = k % nums.size();
        
        std::vector<int> copy(nums.size(), 0);
        
        // Copy all the rotated elements to the front
        int insertIndex = 0;
        for (int i = nums.size() - k; i < nums.size(); ++i) {
            copy[insertIndex++] = nums[i];    
        }
        
        // Copy the beginning of the first array
        for (int i = 0; i < nums.size() - k; ++i) {
            copy[insertIndex++] = nums[i];
        }
        
        // Swap the vectors
        nums.swap(copy);
    }
#endif
};
