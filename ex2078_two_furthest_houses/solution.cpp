class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int minIdx = 0, maxIdx = colors.size() - 1;
        if (colors[minIdx] != colors[maxIdx])
            return maxIdx - minIdx;
        
        int start = 0, end = colors.size() - 1, initialColor(colors[minIdx]);
        while (start <= end) {
            if (colors[start] != initialColor) {
                return std::max(abs(start - minIdx), abs(start - maxIdx));
            } else if (colors[end] != initialColor) {
                return std::max(abs(end - minIdx), abs(end - maxIdx));
            }
            start++, end--;
        }
        
        return - 1;
    }
};
