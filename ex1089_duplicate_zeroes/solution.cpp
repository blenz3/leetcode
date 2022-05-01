class Solution {
public:
    
    // Strategy
    //  - Two passes one to count zeroes and one to copy the values to the end
    void duplicateZeros(vector<int>& arr) {
        int zeroCount(0), length = arr.size() - 1;
        for (int i = 0; i < arr.size() - zeroCount; ++i) {
            if (arr[i] == 0) {
                if (i == length - zeroCount) {
                    arr[length] = 0;
                    length--;
                    break;
                }
                zeroCount++;
            }
        }
        
        // No work to do
        if (zeroCount == 0)
            return;

        // Copy all elements to their final destination
        for (int i = length - zeroCount; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + zeroCount] = 0;
                zeroCount--;
                arr[i + zeroCount] = 0;
            } else {
                arr[i + zeroCount] = arr[i];
            }
        }
    }
    
#if 0
    // Optimized
    //   - Trade off space for time by not doing it in place
    //   - Linear time, linear space
    void duplicateZeros(vector<int>& arr) {
        vector<int> out;
        for (auto val : arr) {
            if (val == 0) {
                out.push_back(val);
            }
            
            out.push_back(val);
        }
        
        // Truncate to original size
        out.erase(out.begin() + arr.size(), out.end());
        
        arr.swap(out);
    }
#endif
    
#if 0
    // Brute force
    //   - For each zero shift everything to the right by one 
    //   - Runtime is n2
    //   - Space is constant
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] != 0)
                continue;
            
            // when it is a zero move everything over by one
            int val = arr[i + 1];
            arr[i + 1] = 0;
            for (int j = i + 2; j < arr.size(); ++j) {
                auto tmp = arr[j];
                arr[j] = val;
                val = tmp;
            }
            
            // Skip over the zero that we've inserted
            i++;
        }
    }
#endif
};
