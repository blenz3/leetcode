class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       return bruteForceRelativeSort(arr1, arr2); 
    }
    
private:
    // Brute force strategy
    //  - Sort larger arrray
    //  - Walk the ordering array and add all the elements over
    //  - Delete all the larger array elements that have been added over
    //  - Copy the remaining and postpend to output
    vector<int> bruteForceRelativeSort(vector<int>& arr1, vector<int>& arr2) {
        std::sort(arr1.begin(), arr1.end());
        std::vector<int> sorted;
        
        for (int x : arr2) {
            int count = std::count(arr1.begin(), arr1.end(), x);
            for (int i = 0; i < count; ++i) {
                sorted.push_back(x);
            }
            arr1.erase(std::remove(arr1.begin(), arr1.end(), x), arr1.end());
        }
        
        for (int x : arr1) 
            sorted.push_back(x);
        
        return sorted;
        
        
        
        
    }
    
};
