---
layout: mypost
title: "Find Median from Data Stream - Classical solution two heaps"
tags: ["Two Pointers", "Design", "Sorting", "Heap (Priority Queue)", "Data Stream", "C++", "Hard"]
---
# Problem Statement:
<p>The <strong>median</strong> is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.</p>

<ul>
	<li>For example, for <code>arr = [2,3,4]</code>, the median is <code>3</code>.</li>
	<li>For example, for <code>arr = [2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code>.</li>
</ul>

<p>Implement the MedianFinder class:</p>

<ul>
	<li><code>MedianFinder()</code> initializes the <code>MedianFinder</code> object.</li>
	<li><code>void addNum(int num)</code> adds the integer <code>num</code> from the data stream to the data structure.</li>
	<li><code>double findMedian()</code> returns the median of all elements so far. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;MedianFinder&quot;, &quot;addNum&quot;, &quot;addNum&quot;, &quot;findMedian&quot;, &quot;addNum&quot;, &quot;findMedian&quot;]
[[], [1], [2], [], [3], []]
<strong>Output</strong>
[null, null, null, 1.5, null, 2.0]

<strong>Explanation</strong>
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>5</sup> &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li>There will be at least one element in the data structure before calling <code>findMedian</code>.</li>
	<li>At most <code>5 * 10<sup>4</sup></code> calls will be made to <code>addNum</code> and <code>findMedian</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>If all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
	<li>If <code>99%</code> of all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
</ul>

# Solution:
This is a classical heaps question.
The solution is to maintain two heaps, a max heap of lower than median values and a min heap of higher than median values. On querying for median, you return from the top of whichever heap as an extra element or in case both have same number of elements (size of array is even), then avarage of top of both heaps.

 {% highlight cpp %} 
class MedianFinder {
public:
    priority_queue<int> q1; //lower half is a max heap
    priority_queue<int, vector<int>, greater<int>> q2; // upper half is a min heap
    MedianFinder() {        
    }
    
    void addNum(int num) {
        if (q1.size()==0 || num < q1.top()) q1.push(num);
        else q2.push(num);
        if (q1.size() > q2.size()+1)
        {
            q2.push(q1.top());
            q1.pop();
        } else if (q2.size() > q1.size()+1)
        {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        int n1=q1.size(), n2=q2.size();
        if (n1 > n2) return q1.top();
        else if (n2 > n1) return q2.top();
        else if (n1==n2) return .5 * (double)q1.top() + .5 * (double)q2.top();
        return -1;
    }
};
 {% endhighlight %}