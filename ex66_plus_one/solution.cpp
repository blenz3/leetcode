class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {   
        int rollover(1);
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            digits[i] += rollover;
            if (digits[i] == 10) 
            {
                digits[i] = 0;
                rollover = 1;
            }
            else
            {
                rollover = 0;
            }
        }
        
        if (rollover != 0)
        {
            digits.insert(digits.begin(), rollover);
        }
        
        return digits;
    }
};