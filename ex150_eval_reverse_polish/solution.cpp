class Solution {
public:
    // Two approaches
    //  - Ceate a tree with operands and values
    //      - Leaves will just be numbers and then we bubble up results by applying intermediate operands
    //      - Seems like a lot of overhead
    //  - Stack
    //      - As numbers are encountered add them to stack
    //      - When operand is encountered pop the previous two values and apply the operand
    //      - Push results back onto the stack as a subexpression result
    int evalRPN(const vector<string>& tokens) {
        stack<int> values;
        for (auto& token : tokens) {
            if (isOperand(token)) {
                int rhs = getAndPop(values);
                int lhs = getAndPop(values);
                values.push(applyOperand(token[0], lhs, rhs));
            } else {
                values.push(parseInt(token));
            }
        }
        
        return values.top();
    }
    
    inline int getAndPop(stack<int>& s) {
        int value = s.top();
        s.pop();
        return value;
    }
    
    int parseInt(const std::string& s) {
        int value;
        ::sscanf(s.c_str(), "%d", &value);
        return value;
    }
    
    bool isOperand(const std::string& s) {
        if (s.length() != 1) 
            return false;
        
        switch (s[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
    }
    
    int applyOperand(char operand, int lhs, int rhs) {
        int result;
        switch (operand) {
            case '+':
                result = lhs + rhs;
                break;
            case '-':
                result = lhs - rhs;
                break;
            case '*':
                result = lhs * rhs;
                break;
            case '/':
                result = lhs / rhs;
                break;
            default:
                result = -1; // uhoh
                break;
        }
        
        return result;
    }
};
