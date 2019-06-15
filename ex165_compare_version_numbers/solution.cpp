class Solution {
public:
    
    int consumeNumber(const char*& s)
    {
        // Just plop back a zero
        if (s == nullptr || *s == '\0')
            return 0;
    
        // Move past the dot
        if (*s == '.')
            s += 1;
        
        // parse the integer
        int val = atoi(s);
        
        // Move the pointer to the end or too the next dot
        while (*s != '.' && *s != '\0') {
            s += 1;
        }
        
        return val;
    }
    
    int compareVersion(string version1, string version2) 
    {
        const char* c1 = version1.c_str(); 
        const char* c2 = version2.c_str();
        
        while (*c1 != '\0' || *c2 != '\0') 
        {
            int v1 = consumeNumber(c1);
            int v2 = consumeNumber(c2);
            
            if (v1 > v2)
                return 1;
            else if (v1 < v2)
                return -1;
        } 
        
        return 0;
    }
};