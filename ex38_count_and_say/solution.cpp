class Solution {
public:
    // Strategy
    //  - Simulate the count and say algorithm from 1..n on the same input
    //  - Return the result
    //  - Runtime quadratic(?), Space is big because for each digit we double the output size 2^N ?
    string countAndSay(int n) {
        if (n < 1) return "";
        
        string result = "1";
        for (int i = 1; i < n; ++i) {
            result = incrementCountAndSay(result);
        }
        
        return result;
    }
    
private:
    string incrementCountAndSay(const string& s) {
        string out;
        
        // for each digit in s we group the number that are the same 
        int count(0);
        char digit = '\0';
        for (int i = 0; i < s.length(); ++i) {
            if (i == 0) {
                digit = s[i];
                count = 1;
            } else if (digit != s[i]) {
                appendDigitalCount(out, count, digit);
                digit = s[i];
                count = 1;
            } else {
                count++;
            }
        }
        
        appendDigitalCount(out, count, digit);
        return out;
        
    }
    
    void appendDigitalCount(string& s, int count, char digit) {
        s.push_back('0' + count);
        s.push_back(digit);
    }
};
