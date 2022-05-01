class Solution {
public:
    // Strategy
    //   - Traverse each string in reverse order and skip deleted characters
    bool backspaceCompare(string s, string t) {
        
        int sIdx = s.length() - 1, tIdx = t.length() - 1;
        while (sIdx >= 0 && tIdx >= 0) {
            // Seek to the next non-deleted character
            sIdx = seek(s, sIdx);
            tIdx = seek(t, tIdx);
            
            // Both strings are totally consumed
            if (sIdx < 0 && tIdx < 0) 
                return true;
            // One string has been totally consumed but the other has not
            else if (sIdx < 0 || tIdx < 0) 
                return false;
            // Compare non-deleted characters
            else if (s[sIdx] != t[tIdx]) 
                return false;
        
            // Continue traversing backwards
            sIdx--, tIdx--;    
        }
        
        // Do a final seek to see if we can get to the end of the characters
        sIdx = seek(s, sIdx);
        tIdx = seek(t, tIdx);
        
        return (sIdx < 0 && tIdx < 0);
    }
    
private:
    int seek(const string& s, int currentIndex) {
        if (currentIndex < 0 || s[currentIndex] != '#')
            return currentIndex;
        
        int deleteCount = 1;
        currentIndex--;
        while (currentIndex >= 0 && (s[currentIndex] == '#' || deleteCount != 0)) {
            if (s[currentIndex] == '#') {
                deleteCount += 2;
            }
            
            currentIndex--;
            deleteCount--;
        }
        
        return currentIndex;
    }
};
