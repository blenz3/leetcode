class Solution {
public:
    
    int jump(const vector<int>& nums) {
        int jumpsSoFar(0), jumpEndIndex(0), farthest(0);
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == jumpEndIndex) {
                jumpsSoFar++;
                jumpEndIndex = farthest;
            }
        }
        
        return jumpsSoFar;
        
    }
    
#if 0
    // Back tracking - times out
    // Takes exponential time
    int jump(vector<int>& nums) {
        return backtrack(0, nums, 0);
    }
    
    int backtrack(int index, const vector<int>& nums, int jumpsSoFar) {
        // Base case we reach the end
        if (index == nums.size() - 1) {
            return jumpsSoFar;
        }
        
        // Try each possible jump starting with the longest
        int jumps = nums[index], minJumps(INT_MAX);
        for (int i = min(index + jumps, static_cast<int>(nums.size()) - 1); i > index; --i) {
            if (nums[i] == 0)
                continue;
            
            // If this one is at the end then we know it's the best we can do
            minJumps = std::min(backtrack(i, nums, jumpsSoFar + 1), minJumps);
            if (i == nums.size() - 1) {
                // this is the best we can do so let's break early
                break;
            } 
        }
        return minJumps;
    }
#endif
};
