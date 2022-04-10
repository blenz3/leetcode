class Solution {
public:


    // Dynamic programming
    //  - As we back track we register when a cell is bad so we never search it again
    
    bool canJump(vector<int>& nums) {
        vector<bool> badSpots(nums.size(), false);
        return backTrack(0, nums, badSpots);
    }
    
     bool backTrack(int index, const vector<int>& nums, vector<bool>& badSpots) {
        // printf("indx %d\n", index);
        if (index >= nums.size() - 1 || nums[index] + index >= nums.size() - 1) 
            return true;
         
        // Bypass previously identified bad spots
        if (badSpots[index]) 
            return false;
        
        for (int i = nums[index]; i > 0; --i) {
            if (backTrack(index + i, nums, badSpots)) 
                return true;
        }
         
         badSpots[index] = true;
        
        return false;
     }
    
#if 0
    // Greedy strategy
    //   - Always take the largest jump
    //   - If the largest jumps won't get us there then there is no way to get there
    bool canJump(vector<int>& nums) {
        int remaining = nums[0], index = 0;
        while (remaining >= 0) {
            if (index >= nums.size() - 1) {
                return true;
            }
            
            if (remaining < nums[index]) {
                remaining = nums[index];
            }
            remaining--;
            if (remaining >= 0)
                index++;
            
        }
        
        return (index >= nums.size() - 1);
    }

    // Permutations based approach
    // Backtracking results in a super long runtime, space is constant
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        
        return backTrack(0, nums);
    }
    
    bool backTrack(int index, const vector<int>& nums) {
        // printf("indx %d\n", index);
        if (index >= nums.size() - 1 || nums[index] + index >= nums.size() - 1) 
            return true;
        
        for (int i = nums[index]; i > 0; --i) {
            if (backTrack(index + i, nums)) 
                return true;
        }
        
        return false;
    }
#endif
};
