class Solution {
public:
    string toLowerCase(string str) {
        for (size_t i = 0; i < str.length(); ++i)
        {
            str[i] = to_lower(str[i]);
        }
        
        return str;
    }
    
    char to_lower(char c)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c -= ('A' - 'a'); // remove the difference between the ASCII 'A' and 'a'
        }
        return c;
    }
};