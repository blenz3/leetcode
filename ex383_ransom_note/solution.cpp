class Solution {
public:
    // Maps
    bool canConstruct(const string& ransomNote, const string& magazine) {
        unordered_map<char, int> ransomCount = characterCount(ransomNote);
        unordered_map<char, int> magazineCount = characterCount(magazine);
        
        for (auto& kvp : ransomCount) {
            if ((magazineCount[kvp.first] -= kvp.second) < 0)
                return false;
        }
        return true;
    }
    
    
    unordered_map<char, int> characterCount(const string& s) {
        unordered_map<char, int> counts;
        for (auto c : s) {
            counts[c]++;
        }
        return counts;
    }
};
