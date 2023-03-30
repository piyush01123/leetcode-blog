---
layout: mypost
title: "Time Based Key-Value Store - HashMap + Ordered Map"
tags: ["Hash Table", "String", "Binary Search", "Design", "C++", "Medium"]
---
# Problem Statement:
<p>Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key&#39;s value at a certain timestamp.</p>

<p>Implement the <code>TimeMap</code> class:</p>

<ul>
	<li><code>TimeMap()</code> Initializes the object of the data structure.</li>
	<li><code>void set(String key, String value, int timestamp)</code> Stores the key <code>key</code> with the value <code>value </code>at the given time <code>timestamp</code>.</li>
	<li><code>String get(String key, int timestamp)</code> Returns a value such that <code>set</code> was called previously, with <code>timestamp_prev &lt;= timestamp</code>. If there are multiple such values, it returns the value associated with the largest <code>timestamp_prev</code>. If there are no values, it returns <code>&quot;&quot;</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;TimeMap&quot;, &quot;set&quot;, &quot;get&quot;, &quot;get&quot;, &quot;set&quot;, &quot;get&quot;, &quot;get&quot;]
[[], [&quot;foo&quot;, &quot;bar&quot;, 1], [&quot;foo&quot;, 1], [&quot;foo&quot;, 3], [&quot;foo&quot;, &quot;bar2&quot;, 4], [&quot;foo&quot;, 4], [&quot;foo&quot;, 5]]
<strong>Output</strong>
[null, null, &quot;bar&quot;, &quot;bar&quot;, null, &quot;bar2&quot;, &quot;bar2&quot;]

<strong>Explanation</strong>
TimeMap timeMap = new TimeMap();
timeMap.set(&quot;foo&quot;, &quot;bar&quot;, 1);  // store the key &quot;foo&quot; and value &quot;bar&quot; along with timestamp = 1.
timeMap.get(&quot;foo&quot;, 1);         // return &quot;bar&quot;
timeMap.get(&quot;foo&quot;, 3);         // return &quot;bar&quot;, since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is &quot;bar&quot;.
timeMap.set(&quot;foo&quot;, &quot;bar2&quot;, 4); // store the key &quot;foo&quot; and value &quot;bar2&quot; along with timestamp = 4.
timeMap.get(&quot;foo&quot;, 4);         // return &quot;bar2&quot;
timeMap.get(&quot;foo&quot;, 5);         // return &quot;bar2&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= key.length, value.length &lt;= 100</code></li>
	<li><code>key</code> and <code>value</code> consist of lowercase English letters and digits.</li>
	<li><code>1 &lt;= timestamp &lt;= 10<sup>7</sup></code></li>
	<li>All the timestamps <code>timestamp</code> of <code>set</code> are strictly increasing.</li>
	<li>At most <code>2 * 10<sup>5</sup></code> calls will be made to <code>set</code> and <code>get</code>.</li>
</ul>

# Solution:
The underlying idea is to use HashMap for key-wise storing data and ordered map for (timestamp,value) pairs ordered by timestamp for each key. Then we can do `get` and `set` operations for any key using binary search in its corresponding ordered map. More details in comments:

 {% highlight cpp %} 
class TimeMap 
{
	private:
    unordered_map<string, map<int,string>> data;

	public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        if (!data.count(key))    // New key insertion
        {
            data[key] = { {timestamp, value} };
            return;
        }
		// If the same timestamp repeats for any key, replace it. We dont really need this line because of constraint but no harm
        if (data[key].count(timestamp)) data[key].erase(timestamp);
		// Finally insert in ordered map
        data[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        if (!data.count(key)) return "";    // key not found
        auto it = data[key].lower_bound(timestamp);
        if (it != data[key].end() && (*it).first==timestamp)    // Exact timestamp found
            return (*it).second;
        if (it == data[key].begin()) return "";    // timestamp asked is before first time set
        --it;    // it now points to the last time it was set before "timestamp"
        return (*it).second;    // finally return value
    }
};
  {% endhighlight %}