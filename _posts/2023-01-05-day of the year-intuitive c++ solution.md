---
layout: mypost
title: "Day of the Year - Intuitive C++ solution"
tags: ["Math", "String", "C++", "Easy"]
---
# Problem Statement:
<p>Given a string <code>date</code> representing a <a href="https://en.wikipedia.org/wiki/Gregorian_calendar" target="_blank">Gregorian calendar</a> date formatted as <code>YYYY-MM-DD</code>, return <em>the day number of the year</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> date = &quot;2019-01-09&quot;
<strong>Output:</strong> 9
<strong>Explanation:</strong> Given date is the 9th day of the year in 2019.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> date = &quot;2019-02-10&quot;
<strong>Output:</strong> 41
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == &#39;-&#39;</code>, and all other <code>date[i]</code>&#39;s are digits</li>
	<li><code>date</code> represents a calendar date between Jan 1<sup>st</sup>, 1900 and Dec 31<sup>th</sup>, 2019.</li>
</ul>

# Solution:
Make sure to take care of [leap year rule](https://www.mathsisfun.com/leap-years.html).
Examples of leap years: 1992,1996,2000,2004,..,2096,2104

# Code
 {% highlight cpp %} 
class Solution {
public:
    int dayOfYear(string date) {
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int Y=stoi(date.substr(0,4)), M=stoi(date.substr(5,2)), D=stoi(date.substr(8,2));
        if ((Y%4==0 && Y%100>0) || (Y%400==0)) days[1]=29;
        int ctr=0;
        for (int m=0;m<M-1;m++) ctr+=days[m];
        ctr+=D;
        return ctr;
    }
};
 {% endhighlight %}