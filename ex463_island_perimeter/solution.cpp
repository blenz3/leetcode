// Problem: https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    // Strategy is to iterate each cell and then count the unfilled sides
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        
        
        int perimeter = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // printf("check %d, %d\n", i, j);
                perimeter += cellPerimeter(grid, i, j);
            }   
        }
        
        return perimeter;
        
    }
    
    int cellPerimeter(const vector<vector<int>>& grid, int row, int col) {
        
        int perimeter = 0;
        if (grid[row][col] == 0) {
            return perimeter;
        }
        
        // Check up
        if (row == 0 || grid[row - 1][col] == 0) {
            perimeter++;
        }
        
        // Check down
        if (row + 1 == grid.size() || grid[row + 1][col] == 0) {
            perimeter++;
        }
        
        // Check left
        if (col == 0 || grid[row][col - 1] == 0) {
            perimeter++;
        }
        
        // Check right
        if (col + 1 == grid[0].size() || grid[row][col + 1] == 0) {
            perimeter++;
        }
        
        return perimeter;
        
    }
};
