---
layout: mypost
title: "Smallest Number in Infinite Set - Hashset, Min heap based solutions"
tags: ["Hash Table", "Design", "Heap (Priority Queue)", "C++", "Ordered Set", "Medium"]
---
# Problem Statement:
<p>You have a set which contains all positive integers <code>[1, 2, 3, 4, 5, ...]</code>.</p>

<p>Implement the <code>SmallestInfiniteSet</code> class:</p>

<ul>
	<li><code>SmallestInfiniteSet()</code> Initializes the <strong>SmallestInfiniteSet</strong> object to contain <strong>all</strong> positive integers.</li>
	<li><code>int popSmallest()</code> <strong>Removes</strong> and returns the smallest integer contained in the infinite set.</li>
	<li><code>void addBack(int num)</code> <strong>Adds</strong> a positive integer <code>num</code> back into the infinite set, if it is <strong>not</strong> already in the infinite set.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;SmallestInfiniteSet&quot;, &quot;addBack&quot;, &quot;popSmallest&quot;, &quot;popSmallest&quot;, &quot;popSmallest&quot;, &quot;addBack&quot;, &quot;popSmallest&quot;, &quot;popSmallest&quot;, &quot;popSmallest&quot;]
[[], [2], [], [], [], [1], [], [], []]
<strong>Output</strong>
[null, null, 1, 2, 3, null, 1, 4, 5]

<strong>Explanation</strong>
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 1000</code></li>
	<li>At most <code>1000</code> calls will be made <strong>in total</strong> to <code>popSmallest</code> and <code>addBack</code>.</li>
</ul>

# Solution:
My first idea was to use a min heap and store the elements which are added. 

 {% highlight cpp %} 
class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int bot = 1;
    SmallestInfiniteSet() 
    {}
    
    int popSmallest() 
    {
        if (pq.empty()) return bot++;
        int res = pq.top();
        pq.pop();
        return res;
    }
    
    void addBack(int num) 
    {
        if(num<bot) pq.push(num);
    }
};
 {% endhighlight %}
This solution works for 90% of tests but will fail when a number is added back twice, hence it will be present in the heap twice. So, we can track this using a separate hashset.
 {% highlight cpp %} 
class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> myset;
    int bot = 1;
    SmallestInfiniteSet() {}
    
    int popSmallest() 
    {
        if (pq.empty()) return bot++;
        int res = pq.top();
        pq.pop();
        myset.erase(res);
        return res;
    }
    
    void addBack(int num) 
    {
        if (!(num<bot && !myset.count(num))) return;
        pq.push(num);
        myset.insert(num);
    }
};
 {% endhighlight %}
This solution gives us AC and beats 95% of all solutions in runtime.

At this point I noticed that the question has constrained itself to `[1,1000]` so we can exploit this to create a much easier solution
 {% highlight cpp %} 
class SmallestInfiniteSet {
public:
    set<int> myset;
    SmallestInfiniteSet() 
    {
        for(int i=1; i<=1000; i++) myset.insert(i);
    }
    
    int popSmallest() 
    {
        int res = *myset.begin();
        myset.erase(res);
        return res;
    }
    
    void addBack(int num) 
    {
        myset.insert(num);
    }
};
 {% endhighlight %}
This also gives us an AC but beats only 40% of all solutions in runtime.

**Analysis**: Both solutions have $O((m+n)\log(n))$ TC and $O(n)$ SC. Here $m$ is the number of calls and $n$ is maximum size of `num`.