class Solution {
public:
    int trap(vector<int>& height) 
    {
        if (height.empty() || height.size() == 1)
            return 0;
        
        std::vector<int> left;   
        left.push_back(height[0]);
        
        int max_so_far(height[0]);
        for (int i = 1; i < height.size(); ++i)
        {
            left.push_back(max_so_far);
            max_so_far = std::max(max_so_far, height[i]);
        }

        std::vector<int> right(height.size());
        right[height.size() - 1] = height.back();
        max_so_far = height.back();
        
        for (int i = height.size() - 2; i >= 0; --i)
        {
            right[i] = max_so_far;
            max_so_far = std::max(height[i], max_so_far);            
        }
        
        std::vector<int> minimum_heights(height.size());
        for (int i = 0; i < height.size(); ++i)
        {
            minimum_heights[i] = std::min(left[i], right[i]);
        }
        
        int sum(0);
        for (int i = 0; i < height.size(); ++i)
        {
            if (minimum_heights[i] - height[i] > 0)
                sum += minimum_heights[i] - height[i];
        }
        
        return sum;
    }
};