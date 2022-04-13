class Solution {
public:
    bool canPermutePalindrome(const string& s) {
        std::array<uint32_t, 26> counts;
        counts.fill(0);
        
        for (auto c : s) {
            counts[static_cast<uint8_t>(c - 'a')]++;
        }
        
        bool consumedOdd = false;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] % 2 != 0 && !consumedOdd) {
                consumedOdd = true;
            } else if (counts[i] % 2 != 0) {
                return false;
            }
        }
        
        return true;
        
        
    }
};
