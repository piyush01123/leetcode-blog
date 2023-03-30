class MyStack {
public:
    queue<int> qu;
    MyStack() {
        qu = {};
    }
    
    void push(int x) {
        qu.push(x);
    }
    
    int pop() {
        queue<int> qv;
        while (qu.size()>1){qv.push(qu.front());qu.pop();}
        int top=qu.front(); qu.pop();
        qu = qv;
        return top;
    }
    
    int top() {
        queue<int> qv;
        while (qu.size()>1){qv.push(qu.front());qu.pop();}
        int top=qu.front(); qu.pop();
        qu = qv;
        qu.push(top);
        return top;
    }
    
    bool empty() {
        return qu.size()==0;
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