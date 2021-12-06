class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       // return bruteForceRelativeSort(arr1, arr2); 
       return slightlyOptimizedRelativeSort(arr1, arr2);
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
    
    // Slightly optimized
    //  - Create a hash map representing each count of the elements in the relative sort array
    //  - Create an ordered map representing the order and count of elements not in the relative sort array
    vector<int> slightlyOptimizedRelativeSort(vector<int>& v1, vector<int>& v2) {
        // Capture each of the elements in the relative sort array
        std::unordered_map<int, int> elementsInRelativeSortArray;
        for (auto x : v2) {
            elementsInRelativeSortArray[x] = 0;
        }
        
        std::map<int, int> elementsNotInRelativeSortArray;
        for (auto x : v1) {
            auto findIt = elementsInRelativeSortArray.find(x);
            if (findIt != elementsInRelativeSortArray.end()) {
                findIt->second++;
            } else {
                elementsNotInRelativeSortArray[x]++;
            }
        }
        
        // Populate the output list. First with the elements in the relative sort array
        std::vector<int> out;
        for (auto value : v2) {
            for (int i = 0; i < elementsInRelativeSortArray[value]; ++i) {
                out.push_back(value);
            }
        }
        
        for (auto kv : elementsNotInRelativeSortArray) {
            for (int i = 0; i < kv.second; ++i) {
                out.push_back(kv.first);
            }
        }
        
        return out;
    }
    
};
