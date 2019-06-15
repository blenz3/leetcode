class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount == 0)
            return 0;
        
        std::sort(coins.begin(), coins.end());
        
        std::vector<int> dp(amount + 1, INT_MAX); // Reserve enough for at least one of the least amount
        for (int current_amount = 1; current_amount <= amount; ++current_amount)
        {
            for (auto coin : coins)
            {
               if (current_amount == coin)
                {
                    dp[current_amount] = 1;
                    break;
                }
                else if (current_amount >= coin && dp[current_amount - coin] != INT_MAX)
                {
                    dp[current_amount] = std::min(dp[current_amount - coin] + 1, dp[current_amount]);
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};