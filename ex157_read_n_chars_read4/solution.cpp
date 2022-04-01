/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int offset(0);
        while (offset < n) {
            int bytesRead = read4(buf + offset);
            if (bytesRead == 0)
                break;
            
            offset += bytesRead;
        }
        
        // Null terminate any extra characters
        if (n <= offset)
            buf[n] = '\0';
        
        return offset;
    }
};
