class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left(0), right(height.size() - 1);
        
        int max_area(0);
        while (left < right)
        {
            const int current_area = (height[left] > height[right]) ? height[right] * (right - left): height[left] * (right - left);
            max_area = std::max(max_area, current_area);
            
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        
        return max_area;   
    }
};