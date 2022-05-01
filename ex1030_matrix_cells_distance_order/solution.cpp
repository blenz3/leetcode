class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> out;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                out.push_back({i , j});
            }
        }
        
        std::sort(
            out.begin(), 
            out.end(),
            [&rCenter, &cCenter, this](const vector<int>& lhs, const vector<int>& rhs) {
                return cartesianDistance(lhs, rCenter, cCenter) < cartesianDistance(rhs, rCenter, cCenter); 
            }
        );
        
        return out;
    }
    
    inline int cartesianDistance(const vector<int>& coord, int rCenter, int cCenter) {
        int val = ::abs(coord[0] - rCenter) + ::abs(coord[1] - cCenter);
        // printf("coord (%d, %d) w/ center (%d, %d) has dist %d\n", coord[0], coord[1], rCenter, cCenter, val);
        return val;
    }
};
