struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

class Solution {
public:
    
    struct Fruit {
        int minuteFound;
        int row;
        int col;
        
        Fruit(int min, int r, int c) 
            : minuteFound(min)
            , row(r)
            , col(c)
        {
            
        }
    };
    
    
    // Strategy
    //  - Approach 1: BFS
    //      - Find all fresh oranges and capture their state
    //      - Enqueue each rotten fruit 
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_set<pair<int, int>, pair_hash> freshFruits;
        queue<Fruit> rottenFruits;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    freshFruits.insert(make_pair(i, j));
                } else if (grid[i][j] == 2) {
                    rottenFruits.push(Fruit(0, i, j));
                }
            }
        }
        
        // No fresh fruit at the start so just return
        if (freshFruits.empty()) {
            return 0;
        }
        
        // Start a BFS from each rotten fruit
        int maxTime(0);
        while (!rottenFruits.empty()) {
            auto fruit = rottenFruits.front();
            // printf("Fruit: %d, %d, %d\n", fruit.minuteFound, fruit.row, fruit.col);
            rottenFruits.pop();
            
            // No fresh fruits remain
            if (freshFruits.empty()) {
                // printf("no fresh fruits\n");
                break;
            }
            
            if (grid[fruit.row][fruit.col] == -1) {
                continue;
            }
            
            // This was one hasn't been infected already. Repaint and
            // enqueue those around it
            maxTime = std::max(maxTime, fruit.minuteFound);
            grid[fruit.row][fruit.col] = -1;
            freshFruits.erase(make_pair(fruit.row, fruit.col));
            
            static const vector<pair<int, int>> offsets {
                { 1, 0 }, // Down
                { -1, 0 }, // Up
                { 0, 1 }, // Right
                { 0, -1 } // Left
            };
            
            for (auto [rowOffset, colOffset] : offsets) {
                if (isValid(grid, fruit.row + rowOffset, fruit.col + colOffset)) {
                    rottenFruits.push(Fruit(fruit.minuteFound + 1, fruit.row + rowOffset, fruit.col + colOffset));
                }
            }
            
        }
        return (freshFruits.empty()) ? maxTime : -1;
    }    
    
    bool isValid(const vector<vector<int>>& grid, int row, int col) {
        return !(
            row < 0 ||
            row >= grid.size() ||
            col < 0 ||
            col >= grid[0].size()
        ) &&
        grid[row][col] == 1;
    }
};
