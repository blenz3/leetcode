class Solution {
public:
    // Walk the list and basically attempt perform comparisons for each
    int thirdMax(vector<int>& nums) {
        int64_t largest, middle, third, insertCount(0);
        largest = middle = third = std::numeric_limits<int64_t>::min();
                    
        for (auto num : nums) {
            if (num == largest || num == middle || num == third)  
                continue;
            
            if (num > largest) {
                third = middle;
                middle = largest;
                largest = num;
                insertCount++;
            } else if (num > middle) {
                third = middle;
                middle = num;
                insertCount++;
            } else if (num > third) {
                third = num;
                insertCount++;
            }
        }
        return (insertCount < 3) ? largest : third;
    }
};
