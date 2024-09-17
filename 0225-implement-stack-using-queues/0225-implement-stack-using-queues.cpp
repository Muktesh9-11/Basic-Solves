class MyStack {
public:
    queue<int> q;
    //queue<int> q2;
    int top1=0;
    //int rear=0;
    //int front=0;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
        //rear++;
        top1++;
    }
    
    int pop() {
        if(q.empty()) return -1;
        int x;
        x=q.back();
        for(int i=0;i<q.size()-1;i++){
            int temp=q.front();
            q.push(temp);
            q.pop();
        }
        q.pop();
        //rear--;
        top1--;
        return x;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */