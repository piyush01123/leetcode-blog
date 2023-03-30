---
layout: mypost
title: "Fruit Into Baskets - Reaching the best solution"
tags: ["Array", "Hash Table", "Sliding Window", "C++", "Medium"]
---
# Problem Statement:
<p>You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array <code>fruits</code> where <code>fruits[i]</code> is the <strong>type</strong> of fruit the <code>i<sup>th</sup></code> tree produces.</p>

<p>You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:</p>

<ul>
	<li>You only have <strong>two</strong> baskets, and each basket can only hold a <strong>single type</strong> of fruit. There is no limit on the amount of fruit each basket can hold.</li>
	<li>Starting from any tree of your choice, you must pick <strong>exactly one fruit</strong> from <strong>every</strong> tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.</li>
	<li>Once you reach a tree with fruit that cannot fit in your baskets, you must stop.</li>
</ul>

<p>Given the integer array <code>fruits</code>, return <em>the <strong>maximum</strong> number of fruits you can pick</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> fruits = [<u>1,2,1</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from all 3 trees.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> fruits = [0,<u>1,2,2</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> fruits = [1,<u>2,3,2,2</u>]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= fruits[i] &lt; fruits.length</code></li>
</ul>

# Solution:
We can immediately think of a brute-force $O(n^3)$ solution by checking all subarrays:
 {% highlight cpp %} 
class Solution {
public:
    bool valid(vector<int>&fruits, int i, int j)
    {
        unordered_set<int> unq_fruits;
        for(int k=i; k<=j; k++) unq_fruits.insert(fruits[k]);
        return (unq_fruits.size()<=2);
    }
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0;
        if(n==1) return 1;
        for (int i=0; i<n; i++) for (int j=i+1; j<n; j++)
            if (valid(fruits,i,j)) res=max(res,j-i+1);
        return res;
    }
};
 {% endhighlight %}
This will give us TLE. We can improve it to $O(n^2)$ by noticing that we do not need to check all subarrays. For any starting index, we only extend a subarray to the right as long as it is valid subarray.
 {% highlight cpp %} 
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0;
        if(n==1) return 1;
        for (int i=0; i<n; i++)
        {
            int j=i;
            unordered_set<int> unq_fruits;
            while (j<n)
            {
                if (!unq_fruits.count(fruits[j]) && unq_fruits.size()==2) break;
                unq_fruits.insert(fruits[j]);
                j++;
            }
            res = max(res, j-i);
        }
        return res;
    }
};
 {% endhighlight %}
This also gives us TLE. By now we must realize that HashSet will not be enough, we are going to need HashMap. The crucial use of HashMap is we can know exactly at what index the subarray becomes valid.

 {% highlight cpp %} 
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0, i=0;
        if(n==1) return 1;
        unordered_map<int,int> H;
        for (int j=0; j<n; j++)
        {
            H[fruits[j]]++;
            while(i<n && H.size()>2)
            {
                H[fruits[i]]--;
                if (H[fruits[i]]==0) H.erase(fruits[i]);
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};
 {% endhighlight %}
This is $O(n)$ solution and hence AC. However we can still do a minor improvement: We need not check all valid subarrays, only subarrays longer than the longest valid one we have seen earlier. In this solution, we lose track of the exact `(i,j)` that gives us the answer but the length is what we need. This is still $O(n)$.
 {% highlight cpp %} 
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size(), res=0, i=0,j;
        if(n==1) return 1;
        unordered_map<int,int> H;
        for (j=0; j<n; j++)
        {
            H[fruits[j]]++;
            if(i<n && H.size()>2)
            {
                H[fruits[i]]--;
                if (H[fruits[i]]==0) H.erase(fruits[i]);
                i++;
            }
        }
        return (j-i);
    }
};
 {% endhighlight %}