class Solution {
public:
    int shortestDistance(const vector<string>& words, const string& word1, const string& word2) {
        int word1Idx = -1, word2Idx = -1;
        int minDistance = words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                word1Idx = i;
            } else if (words[i] == word2) {
                word2Idx = i;
            }
            
            if (word1Idx != -1 && word2Idx != -1) {
                minDistance = std::min(minDistance, abs(word1Idx - word2Idx));
            }
        }
        return minDistance;
    }
#if 0
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> words1, words2;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1)
                words1.push_back(i);
            else if (wordsDict[i] == word2)
                words2.push_back(i);
        }
        
        int minDistance = INT_MAX;
        for (int i = 0; i < words1.size(); ++i) {
            for (int j = 0; j < words2.size(); ++j) {
                minDistance = std::min(minDistance, abs(words1[i] - words2[j]));
            }
        }
        
        return minDistance;
    }
#endif
};
