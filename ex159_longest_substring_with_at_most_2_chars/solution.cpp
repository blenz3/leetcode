class Solution {
public:
    // Sliding window
    //  - Basically accumulate until we hit 3 types of characters and then collapse the left bound
    //    until we get back to just one character
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() <= 2) {
            return s.length();
        }
        
        int characterCount = 1, maxLen = 1, start = 0;
        unordered_map<char, int> counts;
        counts[s[0]]++;
        
        for (int i = 1; i < s.length(); ++i) {
            // printf("start = %d, i = %d, eval = %c, count = %d\n", start,i , s[i], counts[s[i]]);
            // printCounts(counts);
            // second character
            if (counts[s[i]] == 0 && characterCount == 1) {
                characterCount++;
                counts[s[i]]++;
                maxLen = std::max(maxLen, i - start + 1);
            } 
            // not a new boy
            else if (counts[s[i]] != 0) {
                counts[s[i]]++;
                maxLen = std::max(maxLen, i - start + 1);
            }
            
            
            // is a new boy that kills our grouping
            else if (counts[s[i]] == 0 && characterCount == 2) {
                while (characterCount != 1) {
                    // printf("truncate %d, %d\n", start, i);
                    if (--counts[s[start++]] == 0) {
                        characterCount--;
                    }
                }
                counts[s[i]]++;
                characterCount++;
                
            }
        }
        
        return maxLen;
        
        
        
    }
    
    void printCounts(const unordered_map<char, int>& counts) {
        printf("{");
        for (auto& kvp : counts) {
            printf("%c -> %d, ", kvp.first, kvp.second);
        }
        printf("}\n");
    }
        
#if 0
    
    
    // Brute force
    //  - Just check each i, j to see if it has only two characters. Keep the max
    //  - Runtime n2, space 1
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() < 2)
            return s.length();
        
        int maxLen(0);
        for (int i = 0; i < s.length(); ++i) {
            char first = s[i], second = '\0';
            for (int j = i + 1; j < s.length(); ++j) {
                if (second == '\0' && s[j] != first) {
                    second = s[j];
                } else if (second != '\0' && s[j] != first && s[j] != second) {
                    break;
                }
                
                maxLen = std::max(maxLen, j - i + 1);
            }
        }
        
        return maxLen;
    }
#endif
};
