class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        if (!checkFormability(s, wordDict)) {
            return false;
        }
        
        // Populate our word dictionary
        std::sort(
            wordDict.begin(),
            wordDict.end(), 
            [](const string& lhs, const string& rhs) { 
                return lhs.size() > rhs.size();
            }
        );
        for (auto& word : wordDict) {
            dictionary[word[0]].push_back(word);
        }
        
        return traverse(s, 0);
    }
private:
    unordered_map<int, bool> memo;
    unordered_map<char, vector<string>> dictionary;
    
    bool checkFormability(const string& s, const vector<string>& wordDict) {
        // Add some pre checks to handle cases where we know that the string will never be 
        // formable from the dictionary word (e.g. all characters in s are in the word dict)
        if (s.empty()) {
            return false;
        }
        
        std::array<int, 256> characterCounts;
        characterCounts.fill(0);
        for (auto& word : wordDict) {
            for (auto c : word) {
                characterCounts[static_cast<size_t>(c)]++;
            }
        }
        
        for (auto& c : s) {
            if (characterCounts[static_cast<size_t>(c)] == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    bool traverse(const string& s, int idx) {
        // We are at or past the end of the string
        if (idx > s.length()) {
            return false;
        } else if (idx == s.length()) {
            return true;
        }
        
        // Check if we've visited here before
        auto memoIt = memo.find(idx);
        if (memoIt != memo.end()) {
            return memoIt->second;
        }
        
        // Check to see if we can match this character to anything in our word dictionary
        auto findIt = dictionary.find(s[idx]);
        if (findIt == dictionary.end()) {
            return false;
        }
        
        // Try out each candidate if it matches
        for (auto& candidate : findIt->second) {
            if (0 != ::strncmp(s.c_str() + idx, candidate.c_str(), std::min(candidate.length(), s.length() - idx))) {
                continue;
            }
            
            if (traverse(s, idx + candidate.length())) {
                memo[idx] = true;
                return true;
            }
        }
        memo[idx] = false;
        return false;
    
    }
};
