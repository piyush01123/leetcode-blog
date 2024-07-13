---
layout: mypost
title: "LRU Cache - Implementing an LRU Cache in C++: Step-by-Step Guide with Code Examples"
tags: ["Hash Table", "Linked List", "Design", "Doubly-Linked List", "C++", "Queue", "Medium"]
---
# Problem Statement:
<p>Design a data structure that follows the constraints of a <strong><a href="https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU" target="_blank">Least Recently Used (LRU) cache</a></strong>.</p>

<p>Implement the <code>LRUCache</code> class:</p>

<ul>
	<li><code>LRUCache(int capacity)</code> Initialize the LRU cache with <strong>positive</strong> size <code>capacity</code>.</li>
	<li><code>int get(int key)</code> Return the value of the <code>key</code> if the key exists, otherwise return <code>-1</code>.</li>
	<li><code>void put(int key, int value)</code> Update the value of the <code>key</code> if the <code>key</code> exists. Otherwise, add the <code>key-value</code> pair to the cache. If the number of keys exceeds the <code>capacity</code> from this operation, <strong>evict</strong> the least recently used key.</li>
</ul>

<p>The functions <code>get</code> and <code>put</code> must each run in <code>O(1)</code> average time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;LRUCache&quot;, &quot;put&quot;, &quot;put&quot;, &quot;get&quot;, &quot;put&quot;, &quot;get&quot;, &quot;put&quot;, &quot;get&quot;, &quot;get&quot;, &quot;get&quot;]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
<strong>Output</strong>
[null, null, null, 1, null, -1, null, -1, 3, 4]

<strong>Explanation</strong>
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= capacity &lt;= 3000</code></li>
	<li><code>0 &lt;= key &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= value &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>2 * 10<sup>5</sup></code> calls will be made to <code>get</code> and <code>put</code>.</li>
</ul>

# Solution:
Suppose we wanted the simplest key-value cache. Here is how we can achieve this:
 {% highlight cpp %} 
class LRUCache {
    unordered_map<int,int> kv;
public:
    LRUCache(int capacity) {}
    int get(int key) {return (kv.count(key)) ? kv[key] : -1;}    
    void put(int key, int value) {kv[key] = value;}
};
 {% endhighlight %}
Now, let us see how to modify it to make it LRU cache. Essentially all we want to do is that each time a key is referred either in `get` or `put` method, the reference is updated and the last refered key is removed from cache when the capacity is exceeded. Assume we have a magical `refer` method that will update the reference and delete the last used reference when capacity exceeds then we could use it like such:
 {% highlight cpp %} 
class LRUCache {
    unordered_map<int, int> kv;
public:
    LRUCache(int capacity) {}
    int get(int key) 
    {
        if(!kv.count(key)) return -1;
        refer(key);
        return kv[key];
    }    
    void put(int key, int value) 
    {
        refer(key);
        kv[key] = value;
    }
    void refer(int key)
    {
        // magical method implementation here
    }
};
 {% endhighlight %}

Now all that remains is to implement the `refer` method. For this we are going to need  a [deque](https://en.wikipedia.org/wiki/Double-ended_queue), basically a queue with push and pop at both ends. In C++ we have [List](https://cplusplus.com/reference/list/list/) for this. The underlying idea is that we maintain the order of reference of keys in this deque. When the capacity is exceeded we erase the last item from the back. At each reference we add or update its reference in the front.


 {% highlight cpp %} 
class LRUCache {
    unordered_map<int, int> kv;
    int csize;
    list<int> dq;
    unordered_map<int, list<int>::iterator> ump;
public:
    LRUCache(int capacity): csize(capacity) {}
    int get(int key) 
    {
        if(!kv.count(key)) return -1;
        refer(key);
        return kv[key];
    }    
    void put(int key, int value) 
    {
        refer(key);
        kv[key] = value;
    }
    void refer(int key)
    {
        if(!ump.count(key))
        {
            if(dq.size()==csize)
            {
                int lastKey = dq.back();
                dq.pop_back();
                ump.erase(lastKey);
                kv.erase(lastKey);
            }
        } 
        else
            dq.erase(ump[key]);
        dq.push_front(key);
        ump[key] = dq.begin();
    }
};
 {% endhighlight %}