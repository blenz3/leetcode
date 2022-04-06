class Solution {
public:
    // Matrix calculations caching
    // [1, 1,  1,  1,  1]
    // [1, 2,  3,  4,  5]
    // [1, 3,  6, 10, 15]
    // [1, 4, 10, 20, 35]
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix;
        for (int i = 0; i < m; ++i) {
            matrix.push_back(vector<int>(n, 1));
        }
        
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        
        return matrix[m - 1][n - 1];
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
    // BFS 
    //   - Times out
    
    int uniquePaths(int m, int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        
        int totalPaths(0);
        while (!q.empty()) {
            auto top = q.front();
            // printf("evaluating %d %d\n", top.first, top.second);
            // Move down one
            if (top.first < m - 1) {
                q.push(make_pair(top.first + 1, top.second));
            }
            
            // Move right one
            if (top.second < n - 1) {
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
