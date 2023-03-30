class Item
{
    public:
    int val, minVal;
    Item(int a, int b): val(a), minVal(b) {}
};
class MinStack {
    stack<Item> stk;
public:
    MinStack() {}
    
    void push(int val) 
    {
        int minVal = (stk.empty() ? val : min(val, stk.top().minVal));
        stk.push(Item(val, minVal));
    }
    
    void pop() {stk.pop();}
    
    int top() {return stk.top().val;}
    
    int getMin() {return stk.top().minVal;}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */