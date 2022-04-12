class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty()) return arr;
        
        int maxVal = arr.back();
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (i == arr.size() - 1) {
                arr[i] = -1;
            } else {
                // Update max element so far
                int current = arr[i];
                arr[i] = maxVal;
                maxVal = std::max(maxVal, current);
            }
        }
        return arr;
    }
#if 0
    vector<int> replaceElements(vector<int>& arr) {
        std::priority_queue<pair<int /*value*/, int /*index*/>, vector<pair<int, int>>> pq;
        
        for (int i = 0; i < arr.size(); ++i) {
            pq.push(make_pair(arr[i], i));
        }
        
        for (int i = 0; i < arr.size() - 1; ++i) {
            auto top = pq.top();
            // printf("top val %d i %d curridx %d\n", top.first, top.second, i);
            while (top.second <= i) {
                pq.pop();
                top = pq.top();
            } 
                
            
            arr[i] = pq.top().first;
        }
        arr[arr.size() - 1] = -1;
        
        return arr;
    }
#endif
#if 0
    // Brute force
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty())
            return arr;
     
        for (int i = 0; i < arr.size(); ++i) {
            int maxRight = -1;
            for (int j = i + 1; j < arr.size(); ++j) {
                maxRight = std::max(maxRight, arr[j]);
            }
            arr[i] = maxRight;
        }
        
        return arr;
    }
#endif
};
