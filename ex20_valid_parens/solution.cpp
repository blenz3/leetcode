class Solution {
public:
    // Strategy is to insert all the open parens into a stack and pop them off when we encounter a close paren. If the popped
    // element doesn't match the type then it's a failure case. Linear runtime, linear space
    bool isOpenParen(char c)
    {
        return (c == '(' || c == '{' || c == '[');
    }
    
    bool isCloseParen(char c)
    {
        return (c == ')' || c == '}' || c == ']');
    }
    
    bool parenTypesMatch(char c1, char c2)
    {
        return (c1 == '(' && c2 == ')' ) || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
    }
    
    bool isValid(string s) {
        std::stack<char> open_parens;
        for (auto c : s)
        {
            if (isOpenParen(c))
            {
                open_parens.push(c);
            }
            else if (isCloseParen(c))
            {
                if (open_parens.empty())
                    return false; // no open paren for this close
                
                if (!parenTypesMatch(open_parens.top(), c))
                    return false; // mismatched types (e.g. '{' and ')')
                
                open_parens.pop();
            }
        }
        
        return open_parens.empty();
    }
};