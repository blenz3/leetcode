class Solution {
public:
    // Approach 1: Exapnd weights into percentages and then index into it directly
    Solution(vector<int>& w) {
        
        // Get the sum of the weights
        int sum(0);
        for (auto weight : w) {
            sum += weight;
        }
        
        // Set the accumulated weights 
        int accumulator = 0;
        for (auto weight : w) {
            weights.push_back(
                make_pair(
                    static_cast<double>(accumulator) / sum,
                    static_cast<double>(accumulator + weight) / sum
                )
            );
            accumulator += weight;
        }
    }
    
    int pickIndex() {
        
        double randomValue = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        int start = 0, end = weights.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (randomValue >= weights[mid].first && randomValue < weights[mid].second) {
                return mid;
            } else if (randomValue < weights[mid].first) {
                end = mid - 1;    
            } else {
                start = mid + 1;
            }
        }
        
        return -1;
    }
    
private:
    vector<pair<double, double>> weights;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
