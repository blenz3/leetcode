class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        std::array<int, 26> counts;
        wordCounts(chars, counts);
        
        int matchCount(0);
        for (auto& word : words) {
            std::array<int, 26> wordCount;
            wordCounts(word, wordCount);
            if (checkCounts(wordCount, counts))
                matchCount += word.length();
        }
        
        return matchCount;
    }
    
    bool checkCounts(const array<int, 26>& wordCount, const array<int, 26>& charCounts) {
        for (int i = 0; i < wordCount.size(); ++i) {
            if (wordCount[i] > charCounts[i])
                return false;
        }
        
        return true;
    }
    
    void wordCounts(const std::string& s, array<int, 26>& counts) {
        counts.fill(0);
        for (auto c : s) {
            counts[static_cast<int>(c - 'a')]++;
        }
    }
};
