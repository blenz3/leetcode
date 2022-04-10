static const int NOT_FOUND = -1;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return (binarySearchMatrix(matrix, target) != NOT_FOUND);
    }
    
    int binarySearchRow(const vector<int>& row, int target) {
        if (target < row.front() || target > row.back()) {
            return NOT_FOUND;
        }
        
        int start = 0, end = row.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (row[mid] == target) {
                return mid;
            } else if (target < row[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return NOT_FOUND;
    }
    
    int binarySearchMatrix(const vector<vector<int>>& m, int target) {
        int start = 0, end = m.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target >= m[mid][0] && target <= m[mid][m[mid].size() - 1]) {
                return binarySearchRow(m[mid], target);
            } else if (target < m[mid][0]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return NOT_FOUND;
    }
};
