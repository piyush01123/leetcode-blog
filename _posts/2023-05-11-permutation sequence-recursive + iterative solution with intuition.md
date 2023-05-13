---
layout: mypost
title: "Permutation Sequence - Recursive + iterative solution with intuition"
tags: ["Math", "Recursion", "C++", "Java", "Hard"]
---
# Problem Statement:
<p>The set <code>[1, 2, 3, ...,&nbsp;n]</code> contains a total of <code>n!</code> unique permutations.</p>

<p>By listing and labeling all of the permutations in order, we get the following sequence for <code>n = 3</code>:</p>

<ol>
	<li><code>&quot;123&quot;</code></li>
	<li><code>&quot;132&quot;</code></li>
	<li><code>&quot;213&quot;</code></li>
	<li><code>&quot;231&quot;</code></li>
	<li><code>&quot;312&quot;</code></li>
	<li><code>&quot;321&quot;</code></li>
</ol>

<p>Given <code>n</code> and <code>k</code>, return the <code>k<sup>th</sup></code> permutation sequence.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3, k = 3
<strong>Output:</strong> "213"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 4, k = 9
<strong>Output:</strong> "2314"
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 3, k = 1
<strong>Output:</strong> "123"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
	<li><code>1 &lt;= k &lt;= n!</code></li>
</ul>

# Solution:
Observe the following pattern for `n=5, k=87`. We decrement `k` in the beginning to make it `(5,86)`. Consider that `f(a,b) = a/(b!), a%(b!)`.
 {% highlight java %} 
A = [(a,b,c,d,e)]

f(86,4) = 3,14
A=[d,  (a,b,c,e)]

f(14,3) = 2,2
A=[d,c,  (a,b,e)]

f(2,2) = 1,0
A=[d,c,b,  (a,e)]

f(0,1) = 0,0
A=[d,c,b,a,  (e)]
 {% endhighlight %}

*What are we doing here?*
We are finding the next element in remaining array (after sorting). This remaining array is shown in small paranthesis. The way to find this element is to get the value at index `k / (n-1)!`. This is because `n!` is divided in `n` groups of size `(n-1)!` each. So, we would like to know which group `k` falls into. Now, new value of `k` is `k % (n-1)! ` and we want to do similar thing with decremented `n`.

With this intuition, we have the following recursive solution:
 {% highlight java %} 
class Solution {
    vector<int> digits;
    vector<int> F;
public:
    void permute(int n, int k, int pos=0) {
        if (n==0) return;
        int cur = k / F[n-1];
        int rem = k % F[n-1];
        swap(digits[pos+cur], digits[pos]);
        sort(digits.begin()+pos+1, digits.end());
        permute(n-1, rem, pos+1);
    }
    string getPermutation(int n, int k)
    {
        int p=1; F.push_back(1);
        for(int i=1; i<=n; i++) 
        {
            digits.push_back(i); 
            p*=i; 
            F.push_back(p);
        }
        permute(n,k-1);
        string res="";
        for (int digit: digits) res+=to_string(digit);
        return res;
    }
};
 {% endhighlight %}

We can write the same thing in java as well.
 {% highlight java %} 
class Solution {
    int[] digits;
    int[] F;
    void swap(int i, int j)
    {
        int t = digits[i];
        digits[i] = digits[j];
        digits[j] = t;
    }
    void permute(int n, int k, int pos)
    {
        if (n==0) return;
        int cur = k / F[n-1];
        int rem = k % F[n-1];
        swap(cur+pos, pos);
        Arrays.sort(digits, pos+1, digits.length);
        permute(n-1, rem, pos+1);
    }
    public String getPermutation(int n, int k) 
    {
        digits = new int[n];
        F = new int[n+1];
        int p=1; F[0] = 1;
        for(int i=1; i<=n; i++)
        {
            digits[i-1] = i;
            p *= i;
            F[i] = p;
        }
        permute(n,k-1,0);
        String res = "";
        for (int digit: digits) res += Integer.toString(digit);
        return res;
    }
}
 {% endhighlight %}
We can also write an iterative version of the solution.
 {% highlight java %} 
class Solution {
    string getPermutation(int n, int k)
    {
        vector<int> digits(n), F(n+1,1);
        int p=1, pos=0; k--;
        for(int i=1; i<=n; i++){digits[i-1]=i; F[i]=i*F[i-1];}
        while(n--)
        {
            int cur = k / F[n];
            k %= F[n];
            swap(digits[pos+cur], digits[pos]);
            sort(digits.begin() + (++pos), digits.end());
        }
        string res="";
        for (int digit: digits) res+=to_string(digit);
        return res;
    }
};
 {% endhighlight %}

Iterative solution in java:
 {% highlight java %} 
class Solution {
    void swap(int i, int j){int t=digits[i]; digits[i]=digits[j]; digits[j]=t;}
    int[] digits;
    public String getPermutation(int n, int k)
    {
        digits = new int[n];
        int[] F = new int[n+1]; F[0]=1;
        int p=1, pos=0; k--;
        for(int i=1; i<=n; i++){digits[i-1]=i; F[i]=i*F[i-1];}
        while(n-->0)
        {
            int cur = k / F[n];
            k %= F[n];
            swap(pos+cur, pos);
            Arrays.sort(digits,  (++pos), digits.length);
        }
        String res="";
        for (int digit: digits) res+=Integer.toString(digit);
        return res;
    }
};
 {% endhighlight %}

All the solutions have $O(n)$ TC and $O(n)$ SC.