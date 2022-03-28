class Solution {
public:
    // Strategy 
    //  - Use a map to capture the input in a map and count each occurrence in both lists
    //  - Iterate the map and return
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> counts;
        counts.reserve(nums1.size() + nums2.size());
        for (auto val : nums1) {
            counts[val].first++;
        }
        
        for (auto val : nums2) {
            counts[val].second++;
        }
        
        vector<int> out;
        for (auto& kvp : counts) {
            auto& count = kvp.second;
            int intersection = min(count.first, count.second);
            for (int i = 0; i < intersection; ++i)
                out.push_back(kvp.first);
        }
        return out;
    }
};
