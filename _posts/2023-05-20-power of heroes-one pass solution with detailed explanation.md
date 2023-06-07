---
layout: mypost
title: "Power of Heroes - One pass solution with detailed explanation"
tags: ["Array", "Math", "Sorting", "Prefix Sum", "C++", "Hard"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> representing the strength of some heroes. The<b> power</b> of a group of heroes is defined as follows:</p>

<ul>
	<li>Let <code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, ... ,<code>i<sub>k</sub></code> be the indices of the heroes in a group. Then, the power of this group is <code>max(nums[i<sub>0</sub>], nums[i<sub>1</sub>], ... ,nums[i<sub>k</sub>])<sup>2</sup> * min(nums[i<sub>0</sub>], nums[i<sub>1</sub>], ... ,nums[i<sub>k</sub>])</code>.</li>
</ul>

<p>Return <em>the sum of the <strong>power</strong> of all <strong>non-empty</strong> groups of heroes possible.</em> Since the sum could be very large, return it <strong>modulo</strong> <code>10<sup>9 </sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,4]
<strong>Output:</strong> 141
<strong>Explanation:</strong> 
1<sup>st</sup>&nbsp;group: [2] has power = 2<sup>2</sup>&nbsp;* 2 = 8.
2<sup>nd</sup>&nbsp;group: [1] has power = 1<sup>2</sup> * 1 = 1. 
3<sup>rd</sup>&nbsp;group: [4] has power = 4<sup>2</sup> * 4 = 64. 
4<sup>th</sup>&nbsp;group: [2,1] has power = 2<sup>2</sup> * 1 = 4. 
5<sup>th</sup>&nbsp;group: [2,4] has power = 4<sup>2</sup> * 2 = 32. 
6<sup>th</sup>&nbsp;group: [1,4] has power = 4<sup>2</sup> * 1 = 16. 
​​​​​​​7<sup>th</sup>&nbsp;group: [2,1,4] has power = 4<sup>2</sup>​​​​​​​ * 1 = 16. 
The sum of powers of all groups is 8 + 1 + 64 + 4 + 32 + 16 + 16 = 141.

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 7
<strong>Explanation:</strong> A total of 7 groups are possible, and the power of each group will be 1. Therefore, the sum of the powers of all groups is 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

# Solution:
Let us start with a $O(n^2)$ solution. We notice that once the array is sorted, we can fix any two *distinct* indices $i, j$ where $0\leq i,j<n$ and $i \
eq j$ then all subsequences composed of elements in between $i,j$ will have $A_i$ as the minimum and $A_j$ as the maximum. The number of such subsequences is $2^
{j-i-1}$ and so the contribution to answer is $2^{j-i-1} * A_j^2 * A_i$. If we sum this for all pair of indices we get the answer. We will separately handle $i=j$ cases.
 {% highlight cpp %} 
int sumOfPower(vector<int>& nums) {
    int  n=nums.size(), res=0;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++)
        {
            int amin=nums[i], amax=nums[j];
            int nmid = j-i-1;
            if (i==j) res += amax * amax * amin;
            else res += (1<<nmid) * amax * amax * amin;
        }
    }
    return res;
}
 {% endhighlight %}

Now, this will pass for small tests. As $n$ starts to increase, it will fail because looking at the constraints in the question, it seems to demand a single-pass solution.

Consider an input array which is sorted ie $a \leq b \leq c \leq d \leq e$.
 {% highlight cpp %} 
nums = [a,b,c,d,e]
 {% endhighlight %}
Now let us write the answer at each iteration.
$a^3$
$b^3 + b^2a$
$c^3 + c^2b + 2c^2a$
$d^3 + d^2c + 2d^2b + 4c^2a$
$e^2 + e^2d + 2e^2c + 4e^b + 8e^2a$

Final answer is the sum of all of these. Notice the pattern that each iteration, we can compute a variable `pre` and then the contribution is `(pre + nums[i]) * nums[i] * nums[i]` and for the next time `pre` becomes `2*pre + nums[i]`.
For example in the abover example, start with $P=0, R=0$ where `P=pre` and `R=res`, shorthand is used for simplicity.
$P=0, R=0$
After $i=0$, $R+=(0+a)*a^2, P=(2*0)+a$
After $i=1$, $R+=(a+b)*b^2, P=2a+b$
After $i=2$, $R+=(c+2a+b)*c^2, P=4a+2b+c$
After $i=3$, $R+=(d+4a+2b+c)*d^2, P=8a+4b+2c+d$
After $i=4$, $R+=(e+8a*4b+2c+d)*e^2, P=16a+8b+4c+2d+e$

Here is the implementation:
 {% highlight cpp %} 
int sumOfPower(vector<int>& nums) {
    int  n=nums.size();
    int res=0, pre=0;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; i++)
    {
        res += (pre + nums[i]) * nums[i] * nums[i]
        pre = 2*pre + nums[i];
    }
    return res;
}
 {% endhighlight %}

We will need to add modulus operations to deal with big test cases. Also let us use `long long` to avoid edge case integer overflows.
 {% highlight cpp %} 
class Solution {
    int mod=1e9+7;
public:
    int sumOfPower(vector<int>& nums) {
        int  n=nums.size();
        long long res=0, pre=0;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++)
        {
            res += (((pre+nums[i])%mod * nums[i])%mod * nums[i])%mod;
            pre = (pre<<1)%mod + nums[i];
            pre %= mod;
            res %= mod;
        }
        return res;
    }
};
 {% endhighlight %}

$TC: O(n\log(n))$ because there was a sorting step involved. $SC: O(1)$.
