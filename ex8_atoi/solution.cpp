bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int to_digit(char c)
{
    if (!is_digit(c))
        throw std::runtime_error("ERROR: Failed to convert non numeric character!");
    
    return c - '0';
}

class Solution {
public:
    
    int myAtoi(string str) 
    {
        // Seek to the first non-whitespace character 
        int idx(0);
        while (idx < str.size() && str[idx] == ' ')
        {
            idx++;
        }
        
        // Verify we didn't just reach the end of the string
        if (idx >= str.size())
            return 0;
        
        // Check the sign if it exists
        int sign(1);
        if (str[idx] == '+')
        {
            idx++; // we don't need to mutate the sign, but we still need to move to the first number
        }
        else if (str[idx] == '-')
        {
            sign = -1;
            idx++;
        }
            
        int64_t output(0);    
        while (idx < str.size() && is_digit(str[idx]))
        {
            output *= 10;
            output += to_digit(str[idx]);
            
            if (sign == -1 && output * -1 <= std::numeric_limits<int32_t>::min())
            {
                return std::numeric_limits<int32_t>::min();
            }
            else if (sign == 1 && output >= std::numeric_limits<int32_t>::max())
            {
                return std::numeric_limits<int32_t>::max();
            }
            
            idx++;
        }
        
        return output * sign;

    }
    
};