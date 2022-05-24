// https://leetcode.com/problems/range-addition/

class Solution {
public:
    // Strategies
    //  - Brute force
    //      - Create an array and iteratively apply the updates
    //      - Return array
    //      - Runtime not great (O(M * N) where M is length and N is number of updates)
    //  - Alternate approach
    //      - Reduce to an interval based problem where we merge intervals 
    //      - For each update we mark the start as +diff and end as -diff
    //      - To recreate the final array we accumulate across it and overwrite the data as we go
    //      - Runtime O(M + N), Space O(N)
    vector<int> getModifiedArray(int length, const vector<vector<int>>& updates) {
        vector<int> range(length, 0);
        
#if 0
        // Brute force
        for (auto& update : updates) {
            for (int i = update[0]; i <= update[1]; ++i) {
                range[i] += update[2];
            }
        }
#endif
        
        // Alternate approach
        for (const auto& update : updates) {
            int start = update[0], end = update[1], val = update[2];
            range[start] += val;
            if (end + 1 != length)
                range[end + 1] -= val;
        }
        
        int accumulation = 0;
        for (int i = 0; i < range.size(); ++i) {
            accumulation += range[i];
            range[i] = accumulation;
        }
        
        return range;
    }
};
