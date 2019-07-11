class Solution {
public:
    
    string parse_matrix(const std::vector<std::vector<char>>& matrix)
    {
        if (matrix.empty())
            return "";
        
        std::string s;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] != '\0')
                    s.push_back(matrix[i][j]);
            }
        }
        
        return s;
    }
	
	void print_row(const std::vector<char>& row)
	{
		printf("{ ");
		for (int i = 0; i < row.size() - 1; ++i)
		{
			printf("%c, ", row[i]);
		}
		
		printf("%d }\n", row[row.size() - 1]);
	}
	
	void print_matrix(const std::vector<std::vector<char>>& matrix)
	{
		printf("Matrix %d by %d\n", matrix.size(), matrix[0].size());
		for (auto& row : matrix)
			print_row(row);
	}
    
    string convert(string s, int numRows) 
    {
        if (s.empty())
            return s;
        
        if (numRows == 1)
            return s;
        
        // Initialize the zig zag matrix with null terminators
        std::vector<std::vector<char>> zigzags;
        for (int i = 0; i < numRows; ++i)
        {
            zigzags.push_back(std::vector<char>(s.length(), '\0'));
        }
        
        // Start populating the values
        int matrix_row = 0, matrix_col = 0;
        
        bool moving_down(true);
        for (auto c : s)
		{
			// If we are currently in the regime of moving down then keep moving down. We detect the boundary case after populating the last one	
			if (moving_down)
			{
				zigzags[matrix_row++][matrix_col] = c;
			}
			else
			{
				zigzags[matrix_row--][matrix_col++] = c;
			}
			
			// Check the boundaries. If after our new character we 
			if (matrix_row < 0)
			{
				moving_down = !moving_down;
				matrix_row = 1;
                matrix_col--;
			}
			else if (matrix_row >= numRows)
			{
				moving_down = !moving_down;
				matrix_row = numRows - 2;
                matrix_col++;
			}
		}
		//print_matrix(zigzags);
		return parse_matrix(zigzags);
    }
};
