class Solution {
public:
    
    // Optimized
    //   - Maintain a stack that tracks all bars encountered so far as long as they are in ascending
    //     order.
    //   - While the bars are ascending then we know that the largest possible rectangle we are generating
    //     is still increasing. When we encounter a value less than the top we pop everythiing off the 
    //     stack that has larger size to evaluate if those subgroups are bigger than the max area
    //   - Any values left over will just be a continuation of that rectangle at that level from the left
    //   - Stolen from the leetcode solution :( 
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }
    
    // Brute Force
    //   - For each i, j we evaluate the total rectangle size
    //   - We return the largest rectangle that can be created by
    //     those histogram entries
#if 0
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, prevHeight = -1;
        for (int i = 0; i < heights.size(); ++i) {
            
            // Bypass cases where we are evaluating the same thing start number since it will
            // always be the same as previously
            if (prevHeight == heights[i]) {
                continue;    
            } 
            
            prevHeight = heights[i];
            
            // We know that this will always have no area
            if (heights[i] == 0) {
                continue;
            }
            
            int minHeight = INT_MAX;
            for (int j = i; j < heights.size() && heights[j] != 0; ++j) {
                minHeight = std::min(minHeight, heights[j]);
                maxArea = std::max(maxArea, minHeight * (j - i + 1));
            }
        }
        
        return maxArea;
    }
#endif
};
