class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int requiredTimes = nums.size() / 3;
        unordered_map<int, int> counts;
        for (auto num : nums) {
            ++counts[num];
        }
        
        vector<int> out;
        for (auto& kvp : counts) {
            if (kvp.second > requiredTimes) {
                out.push_back(kvp.first);
            }
        }
        return out;
    }
};
