class Solution {
public:
    vector<int> findAnagrams(const string& s, const string& p) {
        // Impossible to have an anagram where the source string is smaller than the anagram string
        if (p.length() > s.length()) {
            return vector<int>{};
        }
        
        vector<int> anagramIndices;
        
        // Get the character counts for the pattern string
        std::array<int, 26> patternCounts;
        populateCounts(p, 0, p.length() - 1, patternCounts);
        
        // Sliding window from 0..p.length() 
        size_t startIndex = 0;
        std::array<int, 26> sourceCounts;
        
        populateCounts(s, 0, p.length() - 1, sourceCounts);
        if (compareCounts(sourceCounts, patternCounts)) {
            anagramIndices.push_back(0);
        }
        
        startIndex++;
        
        for (size_t endIndex = startIndex + p.length() - 1; endIndex < s.length(); ++endIndex) {
            // Remove existing count
            sourceCounts[s[startIndex - 1] - 'a']--;
            
            // Add new character
            sourceCounts[s[endIndex] - 'a']++;
            
            // Compare
            if (compareCounts(sourceCounts, patternCounts)) {
                anagramIndices.push_back(startIndex);
            }
            
            startIndex++;
        }
        
        return anagramIndices;
    }
    
    void populateCounts(const string& s, size_t left, size_t right, std::array<int, 26>& counts) {
        counts.fill(0);
        for (size_t i = left; i <= right; ++i) {
            counts[s[i] - 'a']++;
        }
    }
    
    bool compareCounts(const std::array<int, 26>& left, const std::array<int, 26>& right) {
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        
        return true;
    }
};
