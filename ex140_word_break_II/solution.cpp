class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        if (!checkFormability(s, wordDict)) {
            return {};
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
        
        vector<string*> path;
        vector<string> results;
        traverse(s, 0, path, results);
        return results;
    }
private:
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
    
    void traverse(const string& s, int idx, vector<string*>& path, vector<string>& results) {
        // We are at or past the end of the string
        if (idx > s.length()) {
            return;
        } else if (idx == s.length()) {
            results.push_back(joinStrings(path));
            return;
        }
        
        // Check to see if we can match this character to anything in our word dictionary
        auto findIt = dictionary.find(s[idx]);
        if (findIt == dictionary.end()) {
            return;
        }
        
        // Try out each candidate if it matches
        for (auto& candidate : findIt->second) {
            if (0 != ::strncmp(s.c_str() + idx, candidate.c_str(), std::min(candidate.length(), s.length() - idx))) {
                continue;
            }
            
            path.push_back(&candidate);
            traverse(s, idx + candidate.length(), path, results);
            path.pop_back();
        }
    }
    
    string joinStrings(const vector<string*>& strings) {
        string out;
        for (int i = 0; i < strings.size() - 1; ++i) {
            out += *strings[i] + " ";
        }
        
        return out + *strings.back();
    }
};
