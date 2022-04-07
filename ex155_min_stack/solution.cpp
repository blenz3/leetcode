class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
        : minStack()
        , minSoFar(INT_MAX)
    {
        
    }
    
    void push(int val) {
        if (val < minSoFar) {
            minSoFar = val;
        }
        minStack.push(std::make_pair(val, minSoFar));
    }
    
    void pop() {
        minStack.pop();
        if (minStack.empty()) {
            minSoFar = INT_MAX;
        } else {
            minSoFar = minStack.top().second;
        }
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minSoFar;
    }
  
private:
    std::stack<std::pair<int /*val*/, int /*min*/>> minStack;
    int minSoFar;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
