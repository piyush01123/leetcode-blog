---
layout: mypost
title: "Top K Frequent Words - [C++,Python(3/1 lines)] Two methods: Sorting / Max heap"
tags: ["Hash Table", "String", "Trie", "Sorting", "Heap (Priority Queue)", "Bucket Sort", "Counting", "C++", "Python", "Medium"]
---
# Problem Statement:
<p>Given an array of strings <code>words</code> and an integer <code>k</code>, return <em>the </em><code>k</code><em> most frequent strings</em>.</p>

<p>Return the answer <strong>sorted</strong> by <strong>the frequency</strong> from highest to lowest. Sort the words with the same frequency by their <strong>lexicographical order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;i&quot;,&quot;love&quot;,&quot;leetcode&quot;,&quot;i&quot;,&quot;love&quot;,&quot;coding&quot;], k = 2
<strong>Output:</strong> [&quot;i&quot;,&quot;love&quot;]
<strong>Explanation:</strong> &quot;i&quot; and &quot;love&quot; are the two most frequent words.
Note that &quot;i&quot; comes before &quot;love&quot; due to a lower alphabetical order.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;the&quot;,&quot;day&quot;,&quot;is&quot;,&quot;sunny&quot;,&quot;the&quot;,&quot;the&quot;,&quot;the&quot;,&quot;sunny&quot;,&quot;is&quot;,&quot;is&quot;], k = 4
<strong>Output:</strong> [&quot;the&quot;,&quot;is&quot;,&quot;sunny&quot;,&quot;day&quot;]
<strong>Explanation:</strong> &quot;the&quot;, &quot;is&quot;, &quot;sunny&quot; and &quot;day&quot; are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 500</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
	<li><code>k</code> is in the range <code>[1, The number of <strong>unique</strong> words[i]]</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Could you solve it in <code>O(n log(k))</code> time and <code>O(n)</code> extra space?</p>

# Solution:
# Sorting:
We implement a custom comparator for the condition "sort by frequency (descending) and for same frequency sort by string (ascending)"
 {% highlight python %} 
bool comp(pair<string,int>a, pair<string,int>b)
{
    if (a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> H;
        for (string w: words) H[w]++;
        vector<pair<string,int>> vec;
        for (auto p: H) vec.push_back({p.first,p.second});
        sort(vec.begin(),vec.end(),comp);
        vector<string>res;
        for (int i=0; i<k; ++i) res.push_back(vec[i].first);
        return res;
    }
};
 {% endhighlight %}
Same thing in Python3. Python has inbuilt `collections.Counter` to get frequency map  from array. Also Python's sorting API accepts the use of 2 keys if the first key has equal value, hence we need not write a separate comparator function.
 {% highlight python %} 
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counter = Counter(words)
        sorted_words = sorted(counter.keys(), key=lambda i: (-counter[i], i))
        return sorted_words[:k]
 {% endhighlight %}

If you "really" like compact albeit slightly difficult to read code, here is a one-liner for you (though I wont recommend it in real life):
 {% highlight python %} 
def topKFrequent(self, words: List[str], k: int) -> List[str]:
	return [i[0] for i in sorted(Counter(words).items(), key=lambda j: (-j[1],j[0]))][:k]
 {% endhighlight %}

 {% highlight python %} 
TC: O( n log(n))
SC: O(n)
 {% endhighlight %}
# Priority Queue
Instead of sorting we can maintain a priority queue of length K. If length exceeds K, we pop out the last item as per our condition.
 {% highlight python %} 
bool comp(pair<string,int>a, pair<string,int>b)
{
    if (a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> H;
        for (string w: words) H[w]++;
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)*> pq(comp);
        for (auto p: H)
        {
            pq.push({p.first,p.second});
            if (pq.size()>k) pq.pop();
        }
        vector<string>res;
        while (!pq.empty())
        {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }
        return res;
    }
};
 {% endhighlight %}
 {% highlight python %} 
TC: O(n log(K))
SC: O(n)
 {% endhighlight %}
If you have any questions dont hesitate to ask. Please upvote if you find this useful.