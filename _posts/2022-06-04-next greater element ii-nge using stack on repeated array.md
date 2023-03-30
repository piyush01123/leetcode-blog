---
layout: mypost
title: "Next Greater Element II - NGE using stack on repeated array"
tags: ["Array", "Stack", "Monotonic Stack", "C++", "Medium"]
---
# Problem Statement:
<p>Given a circular integer array <code>nums</code> (i.e., the next element of <code>nums[nums.length - 1]</code> is <code>nums[0]</code>), return <em>the <strong>next greater number</strong> for every element in</em> <code>nums</code>.</p>

<p>The <strong>next greater number</strong> of a number <code>x</code> is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn&#39;t exist, return <code>-1</code> for this number.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1]
<strong>Output:</strong> [2,-1,2]
Explanation: The first 1&#39;s next greater number is 2; 
The number 2 can&#39;t find next greater number. 
The second 1&#39;s next greater number needs to search circularly, which is also 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,3]
<strong>Output:</strong> [2,3,4,-1,4]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
The solution is based on NGE. Except that we repeat the input array twice and return the first n elements as the answer.

First let us solve an easier prolem without the circular thing.
NGE problem for an array
----------------

Consider you have an array. The problem is that for each element in the array find the first element to the right of that element which is larger than it. If there is none output -1.
For example , `A=[2,3,1,4]`. Then output is `{2:3,  3:4,  1:-1,  4:-1}`
HOW DO YOU SOLVE THIS?
Answer is to use a monotonically decreasing stack.  Here is the general strategy
1. Start with appending `A[0]` to the stack.
2. As you traverse the array, if you see that `A[i] <= stack top`, push it to the stack making it the new stack top. Thus you will notice that this results in a monotonically decreasing stack.
2. If ever `A[i]` is greater than the stack top, it means you have found NGE for the number which was at the top of the stack (also the smallest). So pop it and add this pair (`stack top` --> `A[i]`) to your answer. Now check for the new stack top. Continue this till this `A[i]` is the NGE for the stack members.
3. After you are done, only those which are greater or equal to `A[i]` will remain in the stack. Now push `A[i]` to the stack as well.
4. At the end, NGE for all elements which remained in the stack is -1.
 {% highlight cpp %} 
vector<int> nextGreaterElements(vector<int> nums) {
	int n=nums.size();
	stack<pair<int,int>> S;
	vector<int> res (n,-1);
	
	for (int i=0; i<n; i++)
	{
		while (!S.empty() && nums[i] > S.top().first)
		{
			res[S.top().second] = nums[i];
			S.pop();
		}
		S.push({nums[i],i});
	}
	return res;
}
 {% endhighlight %}

---


Now for the circular array we just repeat the array twice and run the exact same algorithm.

 {% highlight cpp %} 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for (int i=0; i<n; i++) nums.push_back(nums[i]);

        stack<pair<int,int>> S;
        vector<int> res (2*n,-1);
        
        for (int i=0; i<2*n; i++)
        {
            while (!S.empty() && nums[i] > S.top().first)
            {
                res[S.top().second] = nums[i];
                S.pop();
            }
            S.push({nums[i],i});
        }
        return vector<int>(res.begin(), res.begin()+n);
    }
};
 {% endhighlight %}
