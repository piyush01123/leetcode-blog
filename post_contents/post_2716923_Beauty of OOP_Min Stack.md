We use pre-built stack class but with our own class object instead of int which will have information on minimum value at any point on stack.

```
class Item
{
    public:
    int val;
    int minVal;
    Item(int v, int mv): val(v), minVal(mv){}
};

class MinStack {
    stack<Item> stk;
public:
    MinStack() 
    {}
    
    void push(int val) 
    {
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
```