class Solution {
public:
    bool try_set_bit(char cell_value, uint16_t& storage)
    {
        // don't do anything
        if (cell_value <= '0' || cell_value > '9')
            return true;

        uint16_t bit = (1 << (cell_value - '1'));
        if (storage & bit)
        {
            return false;
        }
        
        storage |= bit;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::array<uint16_t, 9> rows;
        rows.fill(0);
        
        std::array<uint16_t, 9> cols;
        cols.fill(0);
        
        std::array<uint16_t, 9> subboxes;
        subboxes.fill(0);
        
        for (int row_idx = 0; row_idx < rows.size(); ++row_idx)
        {
            uint16_t& row_cells = rows[row_idx];
            for (int col_idx = 0; col_idx < cols.size(); ++col_idx)
            {
                uint16_t& col_cells = cols[col_idx];
                uint16_t& subbox = subboxes[3 * (row_idx / 3) + (col_idx / 3)];
                if (!try_set_bit(board[row_idx][col_idx], row_cells))
                {
                    return false;
                }
                if (!try_set_bit(board[row_idx][col_idx], col_cells))
                {
                    return false;
                }
                
                if (!try_set_bit(board[row_idx][col_idx], subbox))
                {
                    return false;
                }       
            }
        }
         
        return true;
    }
};