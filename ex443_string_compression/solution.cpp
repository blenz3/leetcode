class Solution {
public:
    // Strategy
    //  - Track the current character and keep traversing until it's a different value
    //  - Overwrite the first elements of the vector
    //  - At the end of reading/writing just return the write head
    int compress(vector<char>& chars) {
        size_t writeHead = 0, count = 0;
        char currentCharacter = chars[0];
        for (size_t i = 0; i < chars.size(); ++i) {
            if (currentCharacter == chars[i]) {
                ++count;
                continue;
            }
            
            writeCounts(currentCharacter, count, writeHead, chars);
            currentCharacter = chars[i];
            count = 1;
        }
        
        writeCounts(currentCharacter, count, writeHead, chars);
        return writeHead;
    }
    
    void writeCounts(char c, size_t count, size_t& writeHead, vector<char>& chars) {
        if (count == 1) {
            chars[writeHead++] = c;
            return;
        }
        
        chars[writeHead++] = c;
        auto digits = getDigits(count);
        for (auto digit : digits) {
            chars[writeHead++] = digit;
        }
    }
    
    string getDigits(size_t count) {
        string s;
        while (count != 0) {
            s.push_back('0' + count % 10);
            count /= 10;
        }
        
        std::reverse(s.begin(), s.end());
        return s;
    }
};
