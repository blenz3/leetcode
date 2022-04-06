struct GridNode {
    int x;
    int y;
    int length;
    
    GridNode() : GridNode(0, 0, 0) {}
    
    GridNode(int x_, int y_, int len) : x(x_), y(y_), length(len) { 
    
    }
};

static const int START_TILE = 1;
static const int END_TILE = 2;
static const int WALKABLE = 0;
static const int IMPASSABLE = -1;
static const int PAINTED = 42;

class Solution {
public:
    // DFS and capture the lengths at the end point 
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int walkableTiles(0), startRow(0), startCol(0);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    walkableTiles++;
                } else if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }
        
        return traverse(startRow, startCol, 0, grid, walkableTiles);
        
    }
    
    int traverse(int x, int y, int exploredTiles, vector<vector<int>>& grid, const int walkableTiles) {
        
        if (exploredTiles > walkableTiles)
            return 0;
        
        if (grid[x][y]  != START_TILE) {
            exploredTiles++;
        }
        grid[x][y] = PAINTED;
        
        vector<pair<int, int>> nextTiles;
        
        // Up
        if (x - 1 >= 0)
            nextTiles.push_back(make_pair(x - 1, y));
            
        // Down
        if (x + 1 < grid.size())
            nextTiles.push_back(make_pair(x + 1, y));
        
        // Right
        if (y + 1 < grid[0].size()) 
            nextTiles.push_back(make_pair(x, y + 1));
        
        // Left
        if (y - 1 >= 0)
            nextTiles.push_back(make_pair(x, y - 1));
        
        int childSolutions = 0;
        for (auto& coord : nextTiles) {
            // Already explored
            int nextTile = grid[coord.first][coord.second];
            if (nextTile == PAINTED) 
                continue;
            
            // It's impassable
            if (nextTile == IMPASSABLE)
                continue;
            
            // It's the end. There are no other solutions in this case
            if (nextTile == END_TILE) {
                if (exploredTiles == walkableTiles)
                    childSolutions += 1;
                
                continue;
            } 
            
            // Get possible child solutions
            childSolutions += traverse(coord.first, coord.second, exploredTiles, grid, walkableTiles);
        }

        grid[x][y] = WALKABLE;
        
        return childSolutions;
    }
};
