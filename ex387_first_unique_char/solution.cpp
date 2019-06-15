class Solution {
public:
    using CharacterMap = std::array<int, 256>;
    
    int firstUniqChar(string s)
    {
        CharacterMap m;
        m.fill(0);
        
        // Provide a count of each character
        for (auto c : s) m[c]++;
        
        for (int i = 0; i < s.size(); ++i)
        {
            // if this is the only occurrence of a string then we return the index
            if (m[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};