class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Check if it is even possible to create this word from the characters in the board
        if (!wordPossible(board, word)) {
            return false;
        }
        
        // Collect all possible start locations
        vector<pair<int, int>> startLocations;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0])
                    startLocations.push_back(make_pair(i, j));
            }
        }
        
        // Attempt to search for each one
        for (auto& start : startLocations) {
            if (searchWord(board, start, word, 0)) {
                return true;
            }
        }
        return false;
    }
    
private:
    bool wordPossible(const vector<vector<char>>& board, const string& word) {
        // There aren't even enough characters to create the word
        if (word.size() > board.size() * board[0].size()) {
            return false;
        }
        
        // Check composition of the board to see if all the characters in word exist in it
        unordered_map<char, int> charCounts;
        for (auto c : word) {
            charCounts[c]++;
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                charCounts[board[i][j]]--;
            }
        }
        
        for (auto& kvp : charCounts) {
            if (kvp.second > 0)
                return false;
        }
        
        return true;
    }
    
    bool searchWord(vector<vector<char>>& board, pair<int, int> coord, const std::string& word, int wordIdx) {        
        // This character doesn't match
        if (board[coord.first][coord.second] != word[wordIdx]) {
            return false;
        }
        
        // Base case we have a match
        if (wordIdx + 1 == word.size()) {
            return true;
        }
        
        // Paint the cell so we don't explore it again
        board[coord.first][coord.second] = '~';
        
        // Evaluate next options
        static const vector<pair<int, int>> offsets { 
            make_pair(-1, 0),
            make_pair(1, 0),
            make_pair(0, -1),
            make_pair(0, +1)
        };
        
        for (auto& offset : offsets) {
            auto nextCoord = make_pair(coord.first + offset.first, coord.second + offset.second);
            if (validCoordinate(nextCoord, board) && searchWord(board, nextCoord, word, wordIdx + 1)) {
                return true;
            }
        }
        
        // Unpaint
        board[coord.first][coord.second] = word[wordIdx];
        
        return false;

    }
    
    bool validCoordinate(pair<int, int> coord, const vector<vector<char>>& board) {
        return (coord.first >= 0 && coord.first < board.size()) &&
               (coord.second >= 0 && coord.second < board[0].size()) &&
               (board[coord.first][coord.second] != '~');
    }
    
};
