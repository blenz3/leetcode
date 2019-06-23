class Solution {
public:
    
    void invertRow(vector<int>& row)
    {
        for (size_t i = 0; i < row.size(); ++i)
        {
            row[i] = !row[i];
        }
    }
    
    void reverseRow(vector<int>& row)
    {
        std::reverse(row.begin(), row.end());
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        for (auto& row : A)
        {
            reverseRow(row);
            invertRow(row);
        }
        
        return A;
    }
};