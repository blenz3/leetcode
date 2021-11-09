class Solution {
public:
    // Brute force solution (O(n) time, O(1) space
    //  - Search across each element in the list. When you find the number return it. If you find a number
    //    larger than the target then return the index
    //
    // Binary search solution(O(lgn)time, O(1) space
    //  - Binary search across the space of the list. If a match is found return the match. Otherwise
    //    determine the appropriate position for the target
    
    int searchInsert(vector<int>& nums, int target) {
        // Brute force solution
        // return linearSearchIndex(nums, target);

        // Optimized solution
        return binarySearchIndex(nums, target);
        // if (nums.empty()) {
        //     return 0;
        // }
        // return binarySearchIndexRec(nums, target, 0, nums.size() - 1);
    }
    
    int linearSearchIndex(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target || nums[i] > target) {
                return i;
            } 
        }
        
        return nums.size();
    }
    
    int binarySearchIndex(vector<int>& nums, int target) { 
        // No elements - insert at 0
        if (nums.empty()) {
            return 0;
        }
        
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int midpoint = (start + end) / 2;
            
            // Exact match
            if (nums[midpoint] == target) {
                return midpoint;
            } else if (target < nums[midpoint]) {
                end = midpoint - 1;
            } else {
                start = midpoint + 1;
            }
        }
        
        return start;
    }
    
    int binarySearchIndexRec(vector<int>& nums, int target, int start, int end) {
        // Only one possibility left
        if (start == end) {
            // Either it is before or after this one
            return (nums[start] < target) ? start + 1 : start;
        } else if (start + 1 == end && nums[start] >= target) {
            return start;
        } else if (start + 1 == end && nums[end] >= target) {
            return end;
        }
        
        int midpoint = start + ((end - start + 1) / 2);
        if (nums[midpoint] == target) {
            return midpoint;
        } else if (nums[midpoint] > target) {
            return binarySearchIndexRec(nums, target, start, midpoint);
        } else {
            return binarySearchIndexRec(nums, target, midpoint, end);
        }
    }
};
