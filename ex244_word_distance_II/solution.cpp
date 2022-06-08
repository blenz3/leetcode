class WordDistance {
public:
    // Create a map of word to vector of index
    // Get the minimum abs difference between the two sets for each pair of words
    WordDistance(vector<string>& wordsDict) {
    
        for (int i = 0; i < wordsDict.size(); ++i) {
            wordIndices[wordsDict[i]].push_back(i);
        }     
        
    }
    
    int shortest(const string& word1, const string& word2) {
        auto find1 = wordIndices.find(word1);
        auto& indices1 = find1->second;
        
        auto find2 = wordIndices.find(word2);
        auto& indices2 = find2->second;
        
        int minDiff = INT_MAX;
        for (auto idx1 : indices1) {
            for (auto idx2 : indices2) {
                int diff = ::abs(idx1 - idx2);
                minDiff = std::min(minDiff, diff);
                if (minDiff == 1) {
                    return 1;
                }
            }
        }
        return minDiff;
    }
    
private:
    unordered_map<string, vector<int>> wordIndices;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
