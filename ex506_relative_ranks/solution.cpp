class Solution {
public:
    // Strategy
    //  - Hashtable with score -> < original position, new position >
    //  - Walk sorted locations 
    vector<string> findRelativeRanks(vector<int>& score) {
        
        unordered_map<int, pair<int, int>> scores;
        for (int i = 0; i < score.size(); ++i) { 
            scores[score[i]] = make_pair(i, -1);
        }
        
        std::sort(score.rbegin(), score.rend());
        
        for (int i = 0; i < score.size(); ++i) {
            auto& result = scores[score[i]];
            result.second = i;
        }
        
        vector<string> out(score.size(), "");
        for (auto& kvp : scores) {
            // printf("Result is %d -> (%d, %d)\n", kvp.first, kvp.second.first, kvp.second.second);
            out[kvp.second.first] = getPlace(kvp.second.second);
        }
        
        return out;
    }
    
    string getPlace(int index) {
        if (index == 0) {
            return "Gold Medal";
        } else if (index == 1) {
            return "Silver Medal";
        } else if (index == 2) {
            return "Bronze Medal";
        } else {
            return std::to_string(index + 1);
        }
    }
};
