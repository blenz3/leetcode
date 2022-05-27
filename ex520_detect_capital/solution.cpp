class Solution {
public:
    bool detectCapitalUse(const string& word) {
        bool allCaps = true, firstOnlyCaps = false, noneCaps = true;
        for (int i = 0; i < word.size(); ++i) {
            if (i == 0 && isUpper(word[i])) {
                firstOnlyCaps = true;
            } 
            if (isLower(word[i])) {
                allCaps = false;
            }
            if (isUpper(word[i])) {
                noneCaps = false;
                
            }
            if (i != 0 && isUpper(word[i])) {
                firstOnlyCaps = false;
            }
         
        }
        return allCaps || firstOnlyCaps || noneCaps;
    }
    
    bool isUpper(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    
    bool isLower(char c) {
        return (c >= 'a' && c <= 'z');
    }
};
