class MyQueue {
public:
    MyQueue() : isStack(true) {
        
    }
    
    void push(int x) {
        if (!isStack) {
            flip();
            isStack = true;
        }
        
        getStack().push(x);        
    }
    
    int pop() {
        if (isStack) {
            flip();
            isStack = false;
        }
        
        auto tmp = getStack().top();
        getStack().pop();
        return tmp;
    }
    
    int peek() {
        if (isStack) {
            flip();
            isStack = false;
        }
        
        auto tmp = getStack().top();
        return tmp;
    }
    
    bool empty() {
        return getStack().empty();
    }
    
private:
    bool isStack;
    stack<int> s1, s2;
    
    stack<int>& getStack() {
        return (!s1.empty()) ? s1 : s2;
    }
    
    stack<int>& getEmptyStack() {
        return (s1.empty()) ? s1 : s2;
    }
    
    
    void flip() {
        if (empty())
            return;
        
        auto& q = getStack();
        auto& s = getEmptyStack();
        
        while (!q.empty()) {
            auto tmp = q.top();
            s.push(tmp);
            q.pop();
        }
        
        isStack = true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
