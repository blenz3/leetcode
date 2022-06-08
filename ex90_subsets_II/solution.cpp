class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        result.clear();
        
        vector<int> current;
        generateSubsets(nums, 0, current);
        
        vector<vector<int>> out;
        for (auto& s : result) {
            out.push_back(vector<int>(s.begin(), s.end()));
        }
        
        return out;
    }
    
private:
    set<vector<int>> result;
    
    
    void generateSubsets(vector<int>& nums, size_t index, vector<int>& current) {
        // Base case end of the list
        if (index == nums.size()) {
            result.insert(current);
            return;
        }
        
        // Either add this number or not
        generateSubsets(nums, index + 1, current);
        current.push_back(nums[index]);
        generateSubsets(nums, index + 1, current);
        current.pop_back();
    }
    
    
};
