class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int lastVal = -1;
        while (!q1.empty()) {
            auto tmp = q1.front();
            q1.pop();
            
            if (q1.empty())
                lastVal = tmp;
            else
                q2.push(tmp);
        }
        
        q1.swap(q2);
        
        return lastVal;
        
    }
    
    int top() {
        int lastVal = -1;
        while (!q1.empty()) {
            auto tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            if (q1.empty())
                lastVal = tmp;
        }
        
        q1.swap(q2);
        
        return lastVal;
        
    }
    
    bool empty() {
        return q1.empty();
    }
    
private:
    
    void print() {
        printf("{");
        queue<int> q3(q1);
        while (!q3.empty()) {
            printf("%d, ", q3.front());
            q3.pop();
        }
        printf("}\n");
    }

    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
