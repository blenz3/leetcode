class Solution {
public:
    bool checkRecord(string s) {
        int totalAbsences(0), subsequentLateDays(0), maxLateDays(0);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'A') {
                totalAbsences++;
                subsequentLateDays = 0;
            } else if (s[i] == 'L') {
                subsequentLateDays++;
            } else if (s[i] == 'P') {
                subsequentLateDays = 0;
            }
            
            maxLateDays = std::max(subsequentLateDays, maxLateDays);
        }
        
        return (totalAbsences < 2 && maxLateDays < 3);
    }
};
