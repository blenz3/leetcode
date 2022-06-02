class Solution {
public:
    // Copy the matrix
    //   Runtime O(M*N)
    //   Space O(M*N)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> m;
        for (int i = 0; i < matrix[0].size(); ++i) {
            m.push_back(std::vector<int>(matrix.size(), 0));
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                m[j][i] = matrix[i][j];
            }
        }
        return m;
    }
};
