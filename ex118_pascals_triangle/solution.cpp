class Solution {
public:
    // Strategy is to 
    vector<vector<int>> generate(int numRows)
    {
        // Generate our output vectors and prepopulate them with 1's
        vector<vector<int>> output;
        for (int i = 0; i < numRows; ++i)
        {
            output.push_back(vector<int>(i + 1, 1));
        }
        
        
        // Iterate from row index 2 to numRows and populate all the inner columns
        for (int i = 2; i < numRows; ++i)
        {
            auto& previous_row = output[i - 1];
            auto& current_row = output[i];
            for (int j = 1; j < current_row.size() - 1; ++j)
            {
                current_row[j] = previous_row[j - 1] + previous_row[j];
            }
        }
        
        return output;
    }
};