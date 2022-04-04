class NumArray {
public:
    NumArray(vector<int>& nums) : numbers(nums) {
        int sum(0);
        for (int i = 0; i < numbers.size(); ++i) {
            sum += numbers[i];
            numbers[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return numbers[right];
        } else {
            return numbers[right] - numbers[left - 1];   
        }
         
    }
private:
    vector<int>& numbers;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
