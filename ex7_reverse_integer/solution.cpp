class Solution {
public:
    int reverse(int x)
    {
#if 0
        return reverse_as_string(x);  
#endif
        return reverse_as_binary(x);
    }
    
    // reverse_as_binary() never changes the representation of the number to a string
    // and as such never needs to perform any allocations
    int reverse_as_binary(int x) 
    {
        int64_t reversed_input(0);
        while (x != 0)
        {
            // Push the smallest digit onto the reversed input
            reversed_input += (x % 10); 
            
            // Reduce the input value by an order of magnitude and expand the reversed input
            // by an order of magnitude as long as we haven't exhausted all the input digits
            x /= 10;
            if (x != 0)
                reversed_input *= 10;

        }
        
        // Add the sign back in
        if (x < 0)
            reversed_input *= -1;

        // Handle overflows
        if (reversed_input > std::numeric_limits<int32_t>::max() || reversed_input < std::numeric_limits<int32_t>::min())
            return 0;
        
        return reversed_input;

    }
    
    // reverse_as_string() basically just reverses the digits by converting the actual binary
    // number into a string and reordering the characters. This is obviously not going to be 
    // as fast as just working with the binary data independently.
    int reverse_as_string(int x)
    {
        auto s = std::to_string(x);
        std::reverse(s.begin(), s.end());
        
        int64_t rs(0);
        rs = std::stoll(s);
        if (x < 0)
            rs *= -1;

        if (rs > std::numeric_limits<int32_t>::max() || rs < std::numeric_limits<int32_t>::min())
            return 0;
        
        return static_cast<int>(rs);
    }
};