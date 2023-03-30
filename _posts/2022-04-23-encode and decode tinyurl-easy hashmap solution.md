---
layout: mypost
title: "Encode and Decode TinyURL - Easy HashMap solution"
tags: ["Hash Table", "String", "Design", "Hash Function", "C++", "Medium"]
---
# Problem Statement:
<blockquote>Note: This is a companion problem to the <a href="https://leetcode.com/discuss/interview-question/system-design/" target="_blank">System Design</a> problem: <a href="https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/" target="_blank">Design TinyURL</a>.</blockquote>

<p>TinyURL is a URL shortening service where you enter a URL such as <code>https://leetcode.com/problems/design-tinyurl</code> and it returns a short URL such as <code>http://tinyurl.com/4e9iAk</code>. Design a class to encode a URL and decode a tiny URL.</p>

<p>There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
	<li><code>Solution()</code> Initializes the object of the system.</li>
	<li><code>String encode(String longUrl)</code> Returns a tiny URL for the given <code>longUrl</code>.</li>
	<li><code>String decode(String shortUrl)</code> Returns the original long URL for the given <code>shortUrl</code>. It is guaranteed that the given <code>shortUrl</code> was encoded by the same object.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> url = &quot;https://leetcode.com/problems/design-tinyurl&quot;
<strong>Output:</strong> &quot;https://leetcode.com/problems/design-tinyurl&quot;

<strong>Explanation:</strong>
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= url.length &lt;= 10<sup>4</sup></code></li>
	<li><code>url</code> is guranteed to be a valid URL.</li>
</ul>

# Solution:
 {% highlight cpp %} 
class Solution {
public:
    unordered_map<int,string> int2url;
    unordered_map<string,int> url2int;
    string base_url = "http://tiny.io/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url2int.find(longUrl)==url2int.end())
        {
            int ctr=url2int.size();
            url2int[longUrl] = ctr;
            int2url[ctr] = longUrl;
        }
        return base_url+to_string(url2int[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string nstr = string(shortUrl.begin()+15,shortUrl.end());
        int n = stoi(nstr);
        return int2url[n];
    }
};
 {% endhighlight %}