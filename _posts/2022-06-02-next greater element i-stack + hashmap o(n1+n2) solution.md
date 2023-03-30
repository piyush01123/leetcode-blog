---
layout: mypost
title: "Next Greater Element I - Stack + HashMap O(N1+N2) solution"
tags: ["Array", "Hash Table", "Stack", "Monotonic Stack", "C++", "Easy"]
---
# Problem Statement:
<p>The <strong>next greater element</strong> of some element <code>x</code> in an array is the <strong>first greater</strong> element that is <strong>to the right</strong> of <code>x</code> in the same array.</p>

<p>You are given two <strong>distinct 0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code>, where <code>nums1</code> is a subset of <code>nums2</code>.</p>

<p>For each <code>0 &lt;= i &lt; nums1.length</code>, find the index <code>j</code> such that <code>nums1[i] == nums2[j]</code> and determine the <strong>next greater element</strong> of <code>nums2[j]</code> in <code>nums2</code>. If there is no next greater element, then the answer for this query is <code>-1</code>.</p>

<p>Return <em>an array </em><code>ans</code><em> of length </em><code>nums1.length</code><em> such that </em><code>ans[i]</code><em> is the <strong>next greater element</strong> as described above.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,1,2], nums2 = [1,3,4,2]
<strong>Output:</strong> [-1,3,-1]
<strong>Explanation:</strong> The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,<u>4</u>,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [<u>1</u>,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,<u>2</u>]. There is no next greater element, so the answer is -1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,4], nums2 = [1,2,3,4]
<strong>Output:</strong> [3,-1]
<strong>Explanation:</strong> The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,<u>2</u>,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,<u>4</u>]. There is no next greater element, so the answer is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>4</sup></code></li>
	<li>All integers in <code>nums1</code> and <code>nums2</code> are <strong>unique</strong>.</li>
	<li>All the integers of <code>nums1</code> also appear in <code>nums2</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you find an <code>O(nums1.length + nums2.length)</code> solution?
# Solution:
Firstly it is not an easy problem by any stretch. You need to know about both monotonic stacks and hashmaps and use them in a correct way.
Here is how I did it:
1. Forget about `nums1`. Solve the NGE (Next Greater Element) problem for `nums2` array and store results in a hashmap
2. Traverse through `nums1` and append result for each element from the hashmap (they will all be present because it is a subset of `nums2`) into an array and finally return this array.

The first part is not obvious just like that. So I will explain

---
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

---

If you get this part, then the other part of question (checking for each item in `nums1`) is very easy. Just check the hashmap you have obtained.

My code has the exact same logic I have given above.
 {% highlight cpp %} 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> H;
        stack<int>S;
        int n1=nums1.size(), n2=nums2.size();
        for (int i=0; i<n2; i++)
        {
            while (!S.empty() && nums2[i]>S.top())
            {
                H[S.top()] = nums2[i];
                S.pop();
            }
            S.push(nums2[i]);
        }
        while (!S.empty())
        {
            H[S.top()]=-1;
            S.pop();
        }
        // We have solved NGE problem for nums2. Now we do 2nd part
        vector<int>res;
        for (int num: nums1) res.push_back(H[num]);
        return res;
    }
};
 {% endhighlight %}
 {% highlight cpp %} 
TC: O(N1+N2)
SC: O(N2)
 {% endhighlight %}