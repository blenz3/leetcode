
class Solution {
public:
    
    // Bubble up
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 1; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size() - 1; ++j) {
                // Compare adjacent elements and bubble them up one level
                // printf("bubbling up i j , %d, %d\n", i,j );
                int minimum = std::min(triangle[i][j], triangle[i][j + 1]);
                triangle[i - 1][j] += minimum;
            }
        }
        return triangle[0][0];
    }
    
#if 0
    // Traverse all paths with memoization
    int minimumTotal(const vector<vector<int>>& triangle) {
        unordered_map<uint64_t, int> mins;
        return traverse(triangle, 0, 0, mins);
    }
    
    int traverse(const vector<vector<int>>& triangle, int level, int index, unordered_map<uint64_t, int>& mins) {
        // Check memoization table
        auto findit = mins.find(key(level, index));
        if (findit != mins.end()) {
            return findit->second;
        }
        
        if (level == triangle.size() - 1) {
            return triangle[level][index];
        }

        int minVal = triangle[level][index] + std::min(
            traverse(triangle, level + 1, index, mins),
            traverse(triangle, level + 1, index + 1, mins)
        );
        
        // printf("set %d, %d = %d\n", level, index, minVal);
        mins[key(level, index)] = minVal;
        return minVal;
    }
    
    inline uint64_t key(int i, int j) {
        return (uint64_t) i << 32 | (unsigned int) j;
    }
#endif
};
