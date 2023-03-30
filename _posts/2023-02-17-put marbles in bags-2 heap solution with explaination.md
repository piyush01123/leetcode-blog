---
layout: mypost
title: "Put Marbles in Bags - 2 Heap solution with explaination"
tags: ["Array", "Greedy", "Sorting", "Heap (Priority Queue)", "C++", "Hard"]
---
# Problem Statement:
<p>You have <code>k</code> bags. You are given a <strong>0-indexed</strong> integer array <code>weights</code> where <code>weights[i]</code> is the weight of the <code>i<sup>th</sup></code> marble. You are also given the integer <code>k.</code></p>

<p>Divide the marbles into the <code>k</code> bags according to the following rules:</p>

<ul>
	<li>No bag is empty.</li>
	<li>If the <code>i<sup>th</sup></code> marble and <code>j<sup>th</sup></code> marble are in a bag, then all marbles with an index between the <code>i<sup>th</sup></code> and <code>j<sup>th</sup></code> indices should also be in that same bag.</li>
	<li>If a bag consists of all the marbles with an index from <code>i</code> to <code>j</code> inclusively, then the cost of the bag is <code>weights[i] + weights[j]</code>.</li>
</ul>

<p>The <strong>score</strong> after distributing the marbles is the sum of the costs of all the <code>k</code> bags.</p>

<p>Return <em>the <strong>difference</strong> between the <strong>maximum</strong> and <strong>minimum</strong> scores among marble distributions</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> weights = [1,3,5,1], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6. 
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10. 
Thus, we return their difference 10 - 6 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> weights = [1, 3], k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only distribution possible is [1],[3]. 
Since both the maximal and minimal score are the same, we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= weights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= weights[i] &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
The question amounts to putting up `K-1` walls inside the `weights` array. The score is the sum of all the adjacent members of walls plus `weights[0]+weights[n-1]`.
For example consider the input `weights = [a,b,c,d,e,f,g,h,i], K=3` and if we put up walls like this: `a b c | d e f g |  h i`  then the score is `(a+c) + (d+g) + (h+i)` which can also be written as `(a+i) + (c+d) + (g+h)`.

Now we want to find the difference between minimum and maximum scores. Notice that the first and last elements will always be part of any score. So, we need not consider them to calculate the difference. We can use a max-heap and a min-heap to store the sum of all adjacent pairs. In our example, this will be `a+b, b+c, c+d, d+e, e+f, f+g, g+h, h+i`. Once we have constructed both the heaps, the maximum score is the sum of `K-1` largest numbers from max heap and the minimum score is the sum of `K-1` smallest numbers from the min heap (plus the first and last, but we are ignoring them because they occur in both). Their difference gives us the answer.
 
# Code
 {% highlight cpp %} 
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size(), cur=weights[0];
        if(k==1 || n==k) return 0;
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for (int i=1; i<n; i++)
        {
            if (i>=2) cur -= weights[i-2];
            cur += weights[i];
            max_pq.push(cur);
            min_pq.push(cur);

        }
        long long res = 0;
        for (int i=0; i<k-1; i++)
        {
            res += max_pq.top();
            res -= min_pq.top();
            max_pq.pop();
            min_pq.pop();
        }
        return res;
    }
};
 {% endhighlight %}

# Complexity
TC: $O(n + k\log(n))$, SC: $O(n)$

If you like this post, please upvote it!