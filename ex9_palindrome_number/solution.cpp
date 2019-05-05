class Solution {
public:
    bool isPalindrome(int x) {
        // Per example 2 negative numbers will never be palindromes
        if (x < 0)
        {
            return false;
        }
        
        // Call into the appropriate strategy
        //return isPalindromeUsingReversedStrings(x);
        //return isPalindromeUsingString(x);
        return isPalindromeUsingBinaryRepresentation(x);
    }
    
    // Strategy 1 - Convert to string, make a copy of said string, reverse the copy and compare.
    // Allocations for both strings are probably encountered, the compare goes beyond the middle,
    // overall not great efficiency wise.
    bool isPalindromeUsingReversedStrings(int x)
    {
        auto x_str = std::to_string(x);
        auto rev_x_str = x_str;
        std::reverse(rev_x_str.begin(), rev_x_str.end());
        
        return (x_str == rev_x_str);
    }
    
    // Strategy 2 - Convert to string compare characters on either side of the string. Removes
    // one allocation, the reverse, and half the compares
    bool isPalindromeUsingString(int x)
    {
        auto s = std::to_string(x);
        if (s.length() == 1)
        {
            return true;
        }
        
        // Only traverse to the midpoint since we'll have already compared everything.
        // Also doesn't matter if number of elements is even or odd since in the even
        // case we cmp everything but in the odd case there will be one hold out in the
        // middle which will be equal to itself.
        size_t head = 0, tail = s.length() - 1;
        while (head < tail)
        {
            // Characters 
            if (s[head] != s[tail])
            {
                return false;
            }
            
            head++;
            tail--;
        }
        
        return true;
    }
    
    // Strategy 3 - Binary representation only. Reverse the binary representation of the input integer
    // and just compare the two for equality
    int reverse(int x)
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
        return reversed_input;
    }
    
    bool isPalindromeUsingBinaryRepresentation(int x)
    {
        return (x == reverse(x));
    }
    
};