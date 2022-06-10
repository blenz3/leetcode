class Solution {
public:
    int countSegments(const string& s) {
        if (s.empty())
            return 0;
        
        int segmentCount(0);
        bool inSegment = false;
        for (auto c : s) {
            if (c == ' ' && inSegment) {
                inSegment = false;
            } else if (c != ' ' && !inSegment) {
                inSegment = true;
                segmentCount++;
            }
        }
        return segmentCount;
    }
};
