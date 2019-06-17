class Solution {
public:
    void print(const std::vector<int>& v)
    {
        for (auto x : v)
            std::cout << x << ", ";
        
        std::cout << std::endl;
    }
    vector<int> getRow(int rowIndex)
    {
        std::vector<int> result(rowIndex + 1, 1);
        for (int row = 2; row < rowIndex + 1; ++row)
        {
            //print(result);
            for (int col = row - 1; col > 0; --col)
            {
                result[col] = result[col] + result[col - 1];
            }
        }
        
        return result;
    }
};