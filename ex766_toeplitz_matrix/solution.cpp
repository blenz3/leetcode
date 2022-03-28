class Solution {
public:
    // Strategy
    //  - 0,0 -> 1,1 -> 2,2 ... nxn
    //  - Check each i,j up to i/2 and j/2 
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        // Check the first row
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (!checkDiagonal(matrix, 0, i)) {
                return false;
            }
        }
        
        // Check the first column
        for (int i = 1; i < matrix.size(); ++i) {
            if (!checkDiagonal(matrix, i, 0))
                return false;
        }
        
        return true;
    }
    
    bool checkDiagonal(const vector<vector<int>>& matrix, int row, int col) {
        int val = matrix[row][col];
        while (row < matrix.size() && col < matrix[0].size()) {
            if (matrix[row][col] != val) 
                return false;
            row++, col++;
        }
            
        return true;
    }
};
