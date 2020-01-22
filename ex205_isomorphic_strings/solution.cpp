class Solution {
public:
    
    static const int MAX_CHARACTERS = 256;
    
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        std::array<char, MAX_CHARACTERS> character_transformations;
        character_transformations.fill('\0');
        for (int i = 0; i < s.length(); ++i) {
            
            char transformToCharacter = '\0';
            if (s[i] == t[i]) {
                transformToCharacter = s[i];
            } else {
                transformToCharacter = t[i];
            }
            
            int index = getTransformationIndex(s[i]);
            if (character_transformations[index] == '\0') {
                character_transformations[index] = transformToCharacter;
            } else if (character_transformations[index] != transformToCharacter) {
                return false;
            }
        }   
        
        // Check that no two characters map to the same character
        std::array<int, MAX_CHARACTERS> transform_counts;
        transform_counts.fill(0);
        
        for (auto c : character_transformations) {
            if (c == '\0')
                continue;
            
            int index = getTransformationIndex(c);
            if (++transform_counts[index] > 1) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    
    int getTransformationIndex(const char c) {
        return static_cast<int>(c);
    }
};
