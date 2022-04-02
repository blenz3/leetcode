class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> counts;
        for (auto num : nums1) {
            counts[num].first++;
        }
        
        for (auto num : nums2) {
            counts[num].second++;
        }
        
        vector<int> out;
        for (auto kvp : counts) {
            int value = kvp.first;
            if (std::min(kvp.second.first, kvp.second.second) >= 1)
                out.push_back(value);
        }
        
        return out;
    }
};
