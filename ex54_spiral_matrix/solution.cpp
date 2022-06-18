enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> path;
        traverse(matrix, 0, 0, path, Direction::RIGHT);
        return path;
    }
    
    void traverse(vector<vector<int>>& matrix, int i, int j, vector<int>& path, Direction heading) {
        // Base case where we've visited everything
        if (path.size() == matrix.size() * matrix[0].size())
            return;
        
        // Add to the path and paint the matrix
        path.push_back(matrix[i][j]);
        matrix[i][j] = INT_MAX;
        
        // Get the next coordinate
        auto nextCoord = getNext(make_pair(i, j), matrix, heading);
        if (!isNextValid(nextCoord, matrix)) {
            heading = getNextDirection(heading);
            nextCoord = getNext(make_pair(i, j), matrix, heading);
        }
        
        traverse(matrix, nextCoord.first, nextCoord.second, path, heading);
    }
    
    
    
    Direction getNextDirection(Direction direction) {
        switch (direction) {
            case Direction::UP:
                return Direction::RIGHT;
            case Direction::RIGHT:
                return Direction::DOWN;
            case Direction::DOWN:
                return Direction::LEFT;
            default:
                return Direction::UP;
        }
    }
    
    pair<int, int> getNext(const pair<int, int>& coord, const vector<vector<int>>& grid, Direction direction) {
        auto [row, col] = coord;
        if (direction == Direction::UP) {
            return make_pair(row - 1, col);
        } else if (direction == Direction::DOWN) {
            return make_pair(row + 1, col);
        } else if (direction == Direction::LEFT) {
            return make_pair(row, col - 1);
        } else {
            return make_pair(row, col + 1);
        }
    }
    
    bool isNextValid(const pair<int, int>& coord, const vector<vector<int>>& grid) {
        auto [row, col] = coord;
        return (
            row >= 0 && row < grid.size() && 
            col >= 0 && col < grid[0].size() &&
            grid[row][col] != INT_MAX
        );
    }
    
    
};
