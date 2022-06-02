class Solution {
public:
#if 0
    Solution()
        : minCost(INT_MAX) 
    {
            
    }
#endif
    
    // Optimization
    //   - Since we can only move down and right the minimum value will always be the 
    //     min of current val + up one and val + left one
    //   - For each cell in the pattern 0,0 .. 0,1 .. 1,0 we evaluate the best move
    //   - Once we reach the end we have a value
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int up = (i != 0) ? grid[i - 1][j] : INT_MAX;
                int left = (j != 0) ? grid[i][j - 1] : INT_MAX;
                
                if (i == 0 && j == 0) {
                    // Nothing to do TODO
                    continue;
                } else if (i == 0) {
                    grid[i][j] += left;
                } else if (j == 0) {
                    grid[i][j] += up;
                } else {
                    grid[i][j] += std::min(up, left);
                }
            }
        }
        
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
    
    void print(vector<vector<int>>& matrix) {
        for (auto& row : matrix) {
            print(row);
        }
    }
    
    void print(vector<int>& row) {
        printf("{");
        for (auto val : row) {
            printf(" %d,", val);   
        }
        printf("}\n");
    }
    
#if 0
    // Brute Force
    //   - DFS from start and keep track of current cost
    //   - Once you reach the end capture the cost and compare w/ current lowest
    //   - As we attempt additional paths short circuit after the first complete path
    //     if the value ever exceed that
    //   - Runtime terrible it's of the magnitude 2^n
    int minPathSum(vector<vector<int>>& grid) {
        dfs(grid, 0, 0, 0);
        return minCost;
    }
    
    
private:
    int minCost;
    
    void dfs(vector<vector<int>>& grid, int i, int j, int pathCost) {
        pathCost += grid[i][j];
        
        // Short circuit search if we already know this won't work
        if (pathCost > minCost) {
            return;
        }
        
        // End condition - we are at the end
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            minCost = std::min(minCost, pathCost);
            return;
        }
        
        // Continue search 
        if (i < grid.size() - 1) {
            dfs(grid, i + 1, j, pathCost);
        }
        
        if (j < grid[0].size() - 1) {
            dfs(grid, i, j + 1, pathCost);
        }
    }
#endif
};
