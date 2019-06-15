class Solution {
public:

    
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (auto& s : strs)
        {
            std::string sorted(s);
            std::sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(s);
        }
        
        std::vector<std::vector<std::string>> output_groups;
        for (auto& kvp : groups)
        {
            output_groups.push_back(kvp.second);
        }
        
        return output_groups;
        
    }
};