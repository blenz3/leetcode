using SolutionResult = vector<int>;
using SolutionResults = vector<SolutionResult>;

class Solution {
public:
    
    SolutionResults threeSum(vector<int>& nums) {
        
        // Sorting costs but it lets us handle duplicate solutions and repeated 
        // numbers easily.
        std::sort(nums.begin(), nums.end());
        
        SolutionResults results;
        for (int i = 0; i < nums.size(); ++i) {
            
            // Once we have our first number we basically need to search across the remainder of the 
            // array to get the two numbers to get our total sum of 0.
            int head = i + 1, tail = nums.size() - 1;
            while (head < tail)
            {
                // On a match we capture the result and move the head and tail pointers until 
                // we are evaluating new values 
                int triple_sum = nums[i] + nums[head] + nums[tail];
                if (triple_sum == 0)
                {
                    SolutionResult result { nums[i], nums[head], nums[tail] };
                    addResultSet(result, results);
                    
                    // Shift the head pointer to the first new value
                    while (head < tail && nums[head] == nums[head + 1])
                        head++;
                    
                    // Shift the tail pointer to the first new value
                    while (head < tail && nums[tail] == nums[tail - 1])
                        tail --;
                    
                    // Shift everything one last time.
                    head++;
                    tail--;
                    
                }
                // Our sum is too large so we reduce the tail pointer to get a smaller overall sum (sorted in asc order)
                else if (triple_sum > 0)
                {
                    tail--;
                }
                // Sum is too small so we increase the head pointer to get a larger overall sum
                else
                {
                    head++;
                }
            }
            
        }
        
        return results;
        
    }
private:
    
    // addResultSet() is a simple helper for collating a new solution result into our set of unique solutions.
    // assumes the new_result has values ordered in ascending order.
    void addResultSet(SolutionResult& new_result, SolutionResults& previous_results)
    {   
        bool is_new_result(true);
        for (auto& prev_result : previous_results)
        {            
            if ((prev_result[0] == new_result[0] && prev_result[1] == new_result[1] && prev_result[2] == new_result[2]))
            {
                is_new_result = false;
                break;
            }
        }

        if (is_new_result)
            previous_results.push_back(new_result);
    }
    
};