class Solution {
public:
    // Strategy

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_map<int, bool> remaining;
        for (auto num : nums) 
            remaining[num] = true;
        
        nums.clear();
        permuteRec(nums, remaining, remaining.size(), results);
        
        return results;
    }
    
    void permuteRec(vector<int>& nums, unordered_map<int, bool>& remaining, int remainingCount, vector<vector<int>>& results) 
    {
        
        if (remainingCount == 0) {
            results.push_back(nums);
            return;
        }
        
        for (auto& kvp : remaining) {
            if (!kvp.second) {
                continue;
                
            }
            kvp.second = false;
            nums.push_back(kvp.first);
            permuteRec(nums, remaining, remainingCount - 1, results);
            nums.erase(nums.end() - 1);
            kvp.second = true;        
        }
    }
};
