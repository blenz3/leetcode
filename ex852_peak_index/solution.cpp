class Solution {
public:
    // Binary search
    //  - Looking for the max value in the array
    //  - If mid > end -> end = mid -1
    //  - If mid > start -> start = mid + 1
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start(0), end(arr.size() - 1);
        while (start < end) {
            int midpoint = start + (end - start) / 2;
            
            if (arr[midpoint] < arr[midpoint + 1]) {
                start = midpoint + 1;
            } else {
                end = midpoint;
            }
            
        }
        
        return start;
    }
    
#if 0
    // Linear search for the max
    int peakIndexInMountainArray(vector<int>& arr) {
        int peakIndex(0);
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > arr[peakIndex]) 
                peakIndex = i;
        }
        
        return peakIndex;
    }
#endif
};
