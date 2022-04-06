class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1) 
            return 0;   
        
        // Repaint 1's as zeroes
        for (int i = 0 ; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[0].size(); ++j) {
                obstacleGrid[i][j] = (obstacleGrid[i][j] == 1) ? -1 : 0;
            }
        }
        
        // Paint the starting row and column
        bool isBlocked(false);
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0] == -1)
                break
                
            obstacleGrid[i][0] = 1;
        }
        
        for (int i = 0; i < obstacleGrid[0].size(); ++i) {
            if (obstacleGrid[0][i] == -1)
                break
                
            obstacleGrid[0][i] = 1;
        }
        
        printM(obstacleGrid);
        
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[i].size(); ++j) {
                if (obstacleGrid[i][j] == 0) {
                    
                }
                if (obstacleGrid[i][j] != -1) {
                    int left = (obstacleGrid[i][j - 1] == -1) ? 0 : obstacleGrid[i][j - 1];
                    int right = (obstacleGrid[i - 1][j] == -1) ? 0 : obstacleGrid[i - 1][j];
                    obstacleGrid[i][j] = left + right;
                }
                
            }
        }
        printM(obstacleGrid);
        
        return obstacleGrid.back().back();
    }
    
    void printM(const vector<vector<int>>& m) {
        for (auto& v : m) {
            printf("[");
            for (auto x : v) {
                printf("%d, ", x);
            }
            printf("]\n");
        }   
    }
    
#if 0
    // BFS - times out
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) 
            return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        
        int totalPaths(0);
        while (!q.empty()) {
            auto top = q.front();
            
            // Move down one
            if (top.first < m - 1 && obstacleGrid[top.first + 1][top.second] == 0) {
                q.push(make_pair(top.first + 1, top.second));
            }
            
            // Move right one
            if (top.second < n - 1 && obstacleGrid[top.first][top.second + 1] == 0) {
                q.push(make_pair(top.first, top.second + 1));
            }
            
            
            if (top.first + 1 == m && top.second + 1 == n) {
                totalPaths++;
            }
            
            q.pop();
        }
        
        return totalPaths;
    }
#endif
};
