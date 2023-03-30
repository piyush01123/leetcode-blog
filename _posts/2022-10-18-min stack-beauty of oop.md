---
layout: mypost
title: "Min Stack - Beauty of OOP"
tags: ["Stack", "Design", "C++", "Medium"]
---
# Problem Statement:
<p>Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.</p>

<p>Implement the <code>MinStack</code> class:</p>

<ul>
	<li><code>MinStack()</code> initializes the stack object.</li>
	<li><code>void push(int val)</code> pushes the element <code>val</code> onto the stack.</li>
	<li><code>void pop()</code> removes the element on the top of the stack.</li>
	<li><code>int top()</code> gets the top element of the stack.</li>
	<li><code>int getMin()</code> retrieves the minimum element in the stack.</li>
</ul>

<p>You must implement a solution with <code>O(1)</code> time complexity for each function.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MinStack&quot;,&quot;push&quot;,&quot;push&quot;,&quot;push&quot;,&quot;getMin&quot;,&quot;pop&quot;,&quot;top&quot;,&quot;getMin&quot;]
[[],[-2],[0],[-3],[],[],[],[]]

<strong>Output</strong>
[null,null,null,null,-3,null,0,-2]

<strong>Explanation</strong>
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= val &lt;= 2<sup>31</sup> - 1</code></li>
	<li>Methods <code>pop</code>, <code>top</code> and <code>getMin</code> operations will always be called on <strong>non-empty</strong> stacks.</li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls will be made to <code>push</code>, <code>pop</code>, <code>top</code>, and <code>getMin</code>.</li>
</ul>

# Solution:
We use pre-built stack class but with our own class object instead of int which will have information on minimum value at any point on stack.

 {% highlight cpp %} 
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
 {% endhighlight %}