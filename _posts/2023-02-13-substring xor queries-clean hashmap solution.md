---
layout: mypost
title: "Substring XOR Queries - Clean HashMap solution"
tags: ["Array", "Hash Table", "String", "Bit Manipulation", "C++", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>binary string</strong> <code>s</code>, and a <strong>2D</strong> integer array <code>queries</code> where <code>queries[i] = [first<sub>i</sub>, second<sub>i</sub>]</code>.</p>

<p>For the <code>i<sup>th</sup></code> query, find the <strong>shortest substring</strong> of <code>s</code> whose <strong>decimal value</strong>, <code>val</code>, yields <code>second<sub>i</sub></code> when <strong>bitwise XORed</strong> with <code>first<sub>i</sub></code>. In other words, <code>val ^ first<sub>i</sub> == second<sub>i</sub></code>.</p>

<p>The answer to the <code>i<sup>th</sup></code> query is the endpoints (<strong>0-indexed</strong>) of the substring <code>[left<sub>i</sub>, right<sub>i</sub>]</code> or <code>[-1, -1]</code> if no such substring exists. If there are multiple answers, choose the one with the <strong>minimum</strong> <code>left<sub>i</sub></code>.</p>

<p><em>Return an array</em> <code>ans</code> <em>where</em> <code>ans[i] = [left<sub>i</sub>, right<sub>i</sub>]</code> <em>is the answer to the</em> <code>i<sup>th</sup></code> <em>query.</em></p>

<p>A <strong>substring</strong> is a contiguous non-empty sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;101101&quot;, queries = [[0,5],[1,2]]
<strong>Output:</strong> [[0,2],[2,3]]
<strong>Explanation:</strong> For the first query the substring in range <code>[0,2]</code> is <strong>&quot;101&quot;</strong> which has a decimal value of <strong><code>5</code></strong>, and <strong><code>5 ^ 0 = 5</code></strong>, hence the answer to the first query is <code>[0,2]</code>. In the second query, the substring in range <code>[2,3]</code> is <strong>&quot;11&quot;,</strong> and has a decimal value of <strong>3</strong>, and <strong>3<code> ^ 1 = 2</code></strong>.&nbsp;So, <code>[2,3]</code> is returned for the second query. 

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;0101&quot;, queries = [[12,8]]
<strong>Output:</strong> [[-1,-1]]
<strong>Explanation:</strong> In this example there is no substring that answers the query, hence <code>[-1,-1] is returned</code>.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;1&quot;, queries = [[4,5]]
<strong>Output:</strong> [[0,0]]
<strong>Explanation:</strong> For this example, the substring in range <code>[0,0]</code> has a decimal value of <strong><code>1</code></strong>, and <strong><code>1 ^ 4 = 5</code></strong>. So, the answer is <code>[0,0]</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s[i]</code> is either <code>&#39;0&#39;</code> or <code>&#39;1&#39;</code>.</li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= first<sub>i</sub>, second<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
# Intuition
The idea is to store all (upto 32 digits long) binary substrings of `"s"` in a hashmap and then check the hashmap for each query.

Here is the logic to enumerate all non-zero binary substrings of a string of length 1 to 32:
 {% highlight cpp %} 
for (int i=0; i<s.length(); i++)
{
    if (s[i]=='0') continue;
    int num = 0;
    for (int j=i; j<min(i+32,s.length()); j++) 
    {
        num = (num<<1) + (s[j]-'0');
        cout << "substring:" << s.substr(i,j-i+1) << ",value:" << num << endl; 
    }
}
 {% endhighlight %}
We just need to expand this logic to also consider the substring `"0"` and also to create a hashmap of `num: [i,j]` instead of just printing. 

The hashmap stores the positions of first instance of a substring.

While querying, we are looking for `query[0]^query[1]` because `a^c=b => c=a^b`. If we find it in hashmap we append its positions to result else append `[-1,-1]`.

# Code
 {% highlight cpp %} 
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) 
    {
        unordered_map<int, vector<int>> H;
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]=='0')
            {
                if (!H.count(0)) H[0]={i,i}; 
                continue;
            }
            int num = 0;
            for (int j=i; j<min(i+32,(int)s.length()); j++) 
            {
                num = (num<<1)+(s[j]-'0');
                if (!H.count(num)) H[num] = {i,j};
            }
        }
        vector<vector<int>> res;
        for (auto &query: queries)
        {
            int val = query[0]^query[1];
            if (H.count(val)) res.push_back(H[val]);
            else res.push_back({-1,-1});
        }
        return res;
    }
};
 {% endhighlight %}

# Complexity
TC: $O(n+m)$, SC: $O(n+m)$ where $n=\vert s \vert$, $m=\vert Q \vert $

### Note on limits
Actually we can also change the for loop to only consider substrings of upto 30 digits long: `for (int j=i; j<min(i+30,(int)s.length()); j++)`. This is because both `first` and `second` are in the range $[0,10^9]$, we know that $10^9$ in binary is 30 digits long. Hence their XOR can be at max 30 digits long ie their maximum value can be `2^{30}-1`.

In the current solution written above, the hashmap will also contain -ve numbers which is not useful for us but does us no harm. By changing 32 to 30 in the for loop, we can make hashmap a little bit smaller.
