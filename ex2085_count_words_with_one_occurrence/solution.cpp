class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_set<string> removedWords;
        unordered_map<string, pair<int /*words1 count*/, int /*words2 count*/>> counts;
        
        for (auto& word : words1) {
            if (removedWords.find(word) != removedWords.end())
                continue;
            
            auto findIt = counts.find(word);
            if (findIt == counts.end()) {
                counts[word] = make_pair(1, 0);
            } else {
                counts.erase(word);
                removedWords.insert(word);
            }
        }
        
        for (auto& word : words2) {
            if (removedWords.find(word) != removedWords.end())
                continue;
            
            auto findIt = counts.find(word);
            if (findIt == counts.end()) {
                counts[word] = make_pair(0, 1);
            } else if (findIt->second.second != 0) {
                counts.erase(word);
                removedWords.insert(word);
            } else {
                findIt->second.second++;
            }
        }
        
        int words(0);
        for (auto& kvp : counts) {
            auto& count = kvp.second;
            if (count.first == 1 && count.second == 1)
                words++;
        }
        
        return words;
    }
};
