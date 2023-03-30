
class Item
{
    public:
    int val;
    int minVal;
    Item(int v, int mv): val(v), minVal(mv){}
};

bool comp(Item a, Item b)
{
    return a.val < b.val;
}

class MinStack {
    stack<Item> stk;
public:
    MinStack() 
    {}
    
    void push(int val) {
        int m = (stk.empty()) ? val : min(stk.top().minVal, val);
        stk.push(Item(val, m));
    }
    
    void pop() 
    {
        stk.pop();
    }
    
    int top() 
    {
        return stk.top().val;
    }
    
    int getMin() 
    {
        return stk.top().minVal;
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