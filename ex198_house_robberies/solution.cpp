static const int HOUSE_ALREADY_ROBBED = -1;

class Solution {
public:
    // Use backtracking to attempt all robberies
    //   - space constant (well linear stack space + linear memo table)
    //   - time exponential (for each house we attempt to rob it, but we ultimately only visit each once so linear)
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return simulateRobberies(nums, 0, memo);
    }
    
private:
    
    int simulateRobberies(vector<int>& dollars, size_t houseIdx, vector<int>& memo) {
        // Base case where we've done all robberies
        if (houseIdx >= dollars.size()) {
            return 0;
        }
        
        // See if we've already discovered this house
        if (memo[houseIdx] != HOUSE_ALREADY_ROBBED) {
            return memo[houseIdx];
        }
        
        
        // We haven't observed this spot yet
        int maxDollars = std::max(
            // Don't rob
            simulateRobberies(dollars, houseIdx + 1, memo),
            // Do rob
            simulateRobberies(dollars, houseIdx + 2, memo) + dollars[houseIdx]
        );
        
        memo[houseIdx] = maxDollars;
        
        return maxDollars;
    }
};
