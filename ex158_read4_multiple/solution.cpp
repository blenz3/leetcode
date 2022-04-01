/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    
    Solution() : bytes(0) {

    }
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int offset(0);
        
        // Handle a read from last time
        if (bytes != 0) {
            int copyBytes = std::min(n, bytes);
            ::memcpy(buf, word, copyBytes);
            ::memmove(word, word + copyBytes, bytes - copyBytes);
            bytes -= copyBytes;
            offset += copyBytes;

        }
        
        while (offset < n) {
            bytes = read4(word);
            if (bytes == 0)
                break;
            
            // Copy from out internal word
            int copyBytes = std::min(n - offset, bytes);
            ::memcpy(buf + offset, word, copyBytes);
            
            // Shift any remaining bytes
            if (copyBytes != bytes) {
                ::memmove(word, word + copyBytes, bytes - copyBytes);
            }
            bytes -= copyBytes;
            offset += copyBytes;
        }
        
        // Null terminate any extra characters
        if (n <= offset)
            buf[n] = '\0';
        
        return offset;
    }
    
    char word[4];
    int bytes;
};
