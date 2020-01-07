class Solution {
public:
    // Insert all start indexes and end indexes into an ordered map with a 
    // + 1 or - 1 accumulator modifier for each range begin and end respectively.
    // (O(nlgn) time due to sort, O(n) space due to copy)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::map<int, int> intervalPoints;
        
        for (auto& interval : intervals) {
            intervalPoints[interval[0]] += 1;
            intervalPoints[interval[1]] -= 1;
        }
        
        std::vector<std::vector<int>> mergedIntervals;
        int currentCount = 0, startIndex = 0;
        for (auto& intervalPoint : intervalPoints) {    
        
            if (currentCount == 0) {
                startIndex = intervalPoint.first;
            } 
            
            currentCount += intervalPoint.second;
            if (currentCount == 0) {
                mergedIntervals.push_back(std::vector<int>{startIndex, intervalPoint.first});
            }
            
        }
        return mergedIntervals;
    }
};
