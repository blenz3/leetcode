class Solution {
public:
    int longestPalindrome(string s) {
        array<uint32_t, 256> counts;
        counts.fill(0);
        for (auto c : s) {
            counts[static_cast<uint8_t>(c)]++;
        }
        
        // Sum counts
        int consumedCharacters(0), extra(0);
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] % 2 == 0) {
                consumedCharacters += counts[i];
            } else if (extra == 0) {
                consumedCharacters += counts[i];
                extra++;
            } else {
                consumedCharacters += counts[i] - 1; 
            }
        }
        
        return consumedCharacters;
    }
};
