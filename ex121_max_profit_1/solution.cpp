class Solution {
public:
    
    // Fancy
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty())
            return 0;
            
        int max_profit(0);
        int min_price(prices[0]);
        
        for (int i = 1; i < prices.size(); ++i)
        {
            min_price = std::min<int>(min_price, prices[i]);
            max_profit = std::max<int>(max_profit, prices[i] - min_price);
        }
        
        return max_profit;
    }
    
#if 0
    // Brute force
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty())
            return 0;
            
        int max_profit(0);
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                int profit = (prices[j] - prices[i]);
                if (profit > max_profit)
                {
                    max_profit = profit;
                }
            }
        }
        
        return max_profit;
    }
#endif
};