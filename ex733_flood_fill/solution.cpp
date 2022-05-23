class Solution {
public:
    // Strategy
    //  - From the strating position determine it's initial color and then repaint it the new color
    //  - BFS from that point but only grab new cells if they match the initial color
    //  - Space complexity is going to be linear (queue), time complexity is O(M * N)
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc];
        if (newColor == initialColor) {
            return image;
        }
        
        image[sr][sc] = newColor;
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while (!q.empty()) {
            auto coord = q.front();
            q.pop();
            
            // Check if we need to repaint up
            if (coord.first > 0 && image[coord.first - 1][coord.second] == initialColor) {
                image[coord.first - 1][coord.second] = newColor;
                q.push(make_pair(coord.first - 1, coord.second));
            }
            
            // Check if we need to repaint down
            if (coord.first + 1 != image.size() && image[coord.first + 1][coord.second] == initialColor) {
                image[coord.first + 1][coord.second] = newColor;
                q.push(make_pair(coord.first + 1, coord.second));
                
            }
            // Check if we need to repaint left
            if (coord.second > 0 && image[coord.first][coord.second - 1] == initialColor) {
                image[coord.first][coord.second - 1] = newColor;
                q.push(make_pair(coord.first, coord.second - 1));
            }
            
            // Check if we need to repaint right
            if (coord.second + 1 != image[0].size() && image[coord.first][coord.second + 1] == initialColor) {
                image[coord.first][coord.second + 1] = newColor;
                q.push(make_pair(coord.first, coord.second + 1));
            }
        }
        
        return image;
    }
};
