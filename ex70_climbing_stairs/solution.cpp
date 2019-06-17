class Solution {
public:

    int climbStairs(int N)
    {
        std::unordered_map<int, int> m;
        return climbStairsMemoized(N + 1, m);
        
    }
    
    int climbStairsMemoized(int N, std::unordered_map<int, int>& memoization_table)
    {
        if (N == 0)
            return 0;
        
        if (N == 1)
            return 1;
        
        auto find_it = memoization_table.find(N);
        if (find_it != memoization_table.end())
        {
            return find_it->second;
        }

        int result = climbStairsMemoized(N - 1, memoization_table) + climbStairsMemoized(N - 2, memoization_table);
        memoization_table[N] = result;
        return result;
    }
};
