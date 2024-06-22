class MinStack {
    stack<int> s;
    stack<int> currMin;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (currMin.empty() || val <= currMin.top()) {
            currMin.push(val);
        }
    }
    
    void pop() {
        if (currMin.top() == s.top()) {
            currMin.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return currMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */