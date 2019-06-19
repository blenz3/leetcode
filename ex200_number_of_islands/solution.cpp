class Solution {
public:
    
    enum CellType : char
    {
        WATER = '0',
        LAND = '1',
        ISLAND = '2'
    };
    
    int numIslands(vector<vector<char>>& grid)
    {
        
        // Get the set of coordinate we will have to visit
        
        vector<std::pair<size_t, size_t>> land;
        for (size_t row_idx = 0; row_idx < grid.size(); ++row_idx)
        {
            for (size_t col_idx = 0; col_idx < grid[0].size(); ++col_idx)
            {
                if (CellType::LAND == grid[row_idx][col_idx])
                    land.push_back(std::make_pair(row_idx, col_idx));
            }
        }
        
        // For each land cell we will now do a bfs starting from that point until there are no more unpainted
        // cells. We keep count of how many times we encounter a starting point that is still land to find the 
        // total number of islands
        int num_islands(0);
        for (auto& land_cell : land)
        {
            if (grid[land_cell.first][land_cell.second] != CellType::LAND)
                continue; // this one has already been painted
            
            num_islands++;
                
            // perform the BFS until there are no more cells to visit
            std::stack<std::pair<size_t, size_t>> q;
            q.push(land_cell);
            
            while (!q.empty())
            {
                auto top = q.top();
                q.pop();
                
                auto row_idx = top.first;
                auto col_idx = top.second;
                
                // see if there is anything up one
                if (row_idx != 0 && grid[row_idx - 1][col_idx] == CellType::LAND)
                {
                    q.push(std::make_pair(row_idx - 1, col_idx));
                    grid[row_idx - 1][col_idx] = CellType::ISLAND;
                }
                
                // see if there is anything down one
                if (row_idx + 1 < grid.size() && grid[row_idx + 1][col_idx] == CellType::LAND)
                {
                    q.push(std::make_pair(row_idx + 1, col_idx));
                    grid[row_idx + 1][col_idx] = CellType::ISLAND;
                }
                
                // see if there is anything to the right
                if (col_idx + 1 < grid[0].size() && grid[row_idx][col_idx + 1] == CellType::LAND)
                {
                    q.push(std::make_pair(row_idx, col_idx + 1));
                    grid[row_idx][col_idx + 1] = CellType::ISLAND;
                }
                
                // see if there is anything to the left
                if (col_idx != 0 && grid[row_idx][col_idx - 1] == CellType::LAND)
                {
                    q.push(std::make_pair(row_idx, col_idx - 1));
                    grid[row_idx][col_idx - 1] = CellType::ISLAND;
                }
            }
        }
        
        
        return num_islands;
    }
};