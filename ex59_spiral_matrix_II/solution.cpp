class Solution {
public:
    // Iteratively build the spiral matrix by moving right until we reach and edge or a
    // populated field. Then go down, left, and finally up before reaching the end of 
    // sequence
    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for (int i = 0; i < n; ++i) {
            matrix.push_back(vector<int>(n, -1));
        }
        
        Direction direction = Direction::RIGHT;
        int row = 0, col = 0;
        int i = 1;
        while (i - 1 < n * n) {
            // Paint this cell 
            matrix[row][col] = i;
            
            // Find the next cell we need to paint and handle an exhausted direction (e.g. handle direction changes to spiral)
            auto nextCell = getNextCell(direction, row, col);
            if (!inBounds(matrix, nextCell.first, nextCell.second)) {
                direction = getNextDirection(direction);
                nextCell = getNextCell(direction, row, col);
            } 
            
            row = nextCell.first;
            col = nextCell.second;
            
            i++;
        }
        return matrix;
        
    }
    
    pair<int, int> getNextCell(Direction direction, int row, int col) {
        if (direction == Direction::RIGHT) {
            col += 1;
        } else if (direction == Direction::LEFT) {
            col -= 1;
        } else if (direction == Direction::UP) {
            row -= 1;
        } else {
            row += 1;
        }
        
        return make_pair(row, col);
    }
    
    bool inBounds(const vector<vector<int>>& matrix, int row, int col) {
        if (row >= matrix.size() || col >= matrix.size()) {
            return false;
        }
        
        return (matrix[row][col] == -1);
    }
    
    Direction getNextDirection(Direction direction) {
        Direction next;
        switch (direction) {
            case Direction::UP: 
                next = Direction::RIGHT;
                break;
            case Direction::DOWN:
                next = Direction::LEFT;
                break;
            case Direction::LEFT: 
                next = Direction::UP;
                break;
            default: 
                next = Direction::DOWN;
                break;
        }
        
        return next;
    }
};
