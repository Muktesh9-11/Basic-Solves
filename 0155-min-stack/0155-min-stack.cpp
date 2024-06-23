class MinStack {
public:
stack<int>s,pre;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            pre.push(val);
        }
        else{
            s.push(val);
            pre.push(min(val,pre.top()));
        }
    }
    
    void pop() {
        s.pop();
        pre.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return pre.top();
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