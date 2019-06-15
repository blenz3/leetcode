class Solution {
public:
    // Keep a count of each character for both strings. Iterate those counts and see if there 
    // any discrepancies. Linear time, constant space (array size will be constant 256)
    void getCharacterCounts(const std::string& s, std::array<int, 256>& counts)
    {
        counts.fill(0);
        for (auto c : s)
        {
            counts[static_cast<size_t>(c)]++;
        }
    }
    
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        std::array<int, 256> s_counts, t_counts;
        getCharacterCounts(s, s_counts);
        getCharacterCounts(t, t_counts);
        
        for (size_t i = 0; i < 256; ++i)
        {
            if (s_counts[i] != t_counts[i])
                return false;
        }
        
        return true;
    }
};