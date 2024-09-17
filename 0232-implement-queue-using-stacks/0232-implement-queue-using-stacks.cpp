class MyQueue {
public:
    stack<int> s;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(s.size()==0) return -1;
        //int flag=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int temp=s.top();
            s2.push(temp);
            s.pop();
        }
        int x=s2.top();
        s2.pop();
        for(int i=0;i<n-1;i++){
            int temp=s2.top();
            s.push(temp);
            s2.pop();
        }
        return x;

    }
    
    int peek() {
        int n=s.size();
        for(int i=0;i<n;i++){
            int temp=s.top();
            s2.push(temp);
            s.pop();
        }
        int x=s2.top();
        //s2.pop();
        for(int i=0;i<n;i++){
            int temp=s2.top();
            s.push(temp);
            s2.pop();
        }
        return x;
    }
    
    bool empty() {
        if(s.empty()) return true;
        return false;
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