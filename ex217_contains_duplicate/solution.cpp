class Solution {
public:
    // Simple answer using a hash map (O(n) time, O(n) space)
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (auto num : nums) {
            if (++counts[num] > 1)
                return true;
        }
        
        return false;
        
    }
};
