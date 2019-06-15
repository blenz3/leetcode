class Solution {
public:
    using Coordinate = std::pair<int, int>;
    
    Coordinate RotateCoordinate(Coordinate c, int length)
    {
        return std::make_pair(c.second, length - 1 - c.first);
    }
    
    void rotate(vector<vector<int>>& matrix) 
    {
        const int matrix_size = matrix.size();
        for (int i = 0; i < (matrix_size + 1) / 2; ++i)
        {
            for (int j = i; j < matrix_size - i - 1; ++j)
            {
                // move top 
                int top = matrix[i][j];
                Coordinate new_top = RotateCoordinate(std::make_pair(i, j), matrix_size);

                // move right
                int right = matrix[new_top.first][new_top.second];
                Coordinate new_right = RotateCoordinate(std::make_pair(new_top.first, new_top.second), matrix_size);

                // move bottom
                int bottom = matrix[new_right.first][new_right.second];
                Coordinate new_bottom = RotateCoordinate(std::make_pair(new_right.first, new_right.second), matrix_size);

                // move left
                int left = matrix[new_bottom.first][new_bottom.second];
                Coordinate new_left = RotateCoordinate(std::make_pair(new_bottom.first, new_bottom.second), matrix_size);
                
                matrix[new_top.first][new_top.second] = top;
                matrix[new_right.first][new_right.second] = right;
                matrix[new_bottom.first][new_bottom.second] = bottom;
                matrix[new_left.first][new_left.second] = left;
            }
        }
    }
};