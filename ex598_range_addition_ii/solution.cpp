// Link - https://leetcode.com/problems/range-addition-ii/

class Solution {
public:
    // Optimized solution
    //  - Find the area of the smallest ops x, y
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto& op : ops) {
            m = std::min(m, op[0]);
            n = std::min(n, op[1]);
        }
        
        return m * n;
    }
    
#if 0
    // Brute Force
    //  - Actually simulate all the operations
    //  - Count the number of max elements
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) {
            return m * n;    
        }
        
        vector<vector<int>> matrix;
        for (int i = 0; i < m; ++i) {
            matrix.push_back(vector<int>(n, 0));    
        }
        
        for (auto& op : ops) {
            for (int row = 0; row < op[0]; ++row) {
                for (int col = 0; col < op[1]; ++col) {
                    matrix[row][col]++;
                }
            }
        }
        
        int maxVal = matrix[0][0], count = 0;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == maxVal) {
                    count++;
                }
            }
        }
        
        return count;
    }
#endif
};
