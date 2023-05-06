---
layout: mypost
title: "Dota2 Senate - Simulation using Queue"
tags: ["String", "Greedy", "Queue", "Java", "Medium"]
---
# Problem Statement:
<p>In the world of Dota2, there are two parties: the Radiant and the Dire.</p>

<p>The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise <strong>one</strong> of the two rights:</p>

<ul>
	<li><strong>Ban one senator&#39;s right:</strong> A senator can make another senator lose all his rights in this and all the following rounds.</li>
	<li><strong>Announce the victory:</strong> If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.</li>
</ul>

<p>Given a string <code>senate</code> representing each senator&#39;s party belonging. The character <code>&#39;R&#39;</code> and <code>&#39;D&#39;</code> represent the Radiant party and the Dire party. Then if there are <code>n</code> senators, the size of the given string will be <code>n</code>.</p>

<p>The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.</p>

<p>Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be <code>&quot;Radiant&quot;</code> or <code>&quot;Dire&quot;</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> senate = &quot;RD&quot;
<strong>Output:</strong> &quot;Radiant&quot;
<strong>Explanation:</strong> 
The first senator comes from Radiant and he can just ban the next senator&#39;s right in round 1. 
And the second senator can&#39;t exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> senate = &quot;RDD&quot;
<strong>Output:</strong> &quot;Dire&quot;
<strong>Explanation:</strong> 
The first senator comes from Radiant and he can just ban the next senator&#39;s right in round 1. 
And the second senator can&#39;t exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator&#39;s right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == senate.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>senate[i]</code> is either <code>&#39;R&#39;</code> or <code>&#39;D&#39;</code>.</li>
</ul>

# Solution:
We can think of this problem as a simulation. Consider a queue `Q` where we insert all character of `senate`. Now, if `Q` contains only `D`s or only `R`s then, we can already tell what the answer will be. If not then, we run a simulation till that kind of state is achieved. To run this simulation, we start with 2 variables `ptsD` and `ptsR` which denote points of `Dire` and `Radiant` respectively. Now if we encounter `D` then we check whether we can delete this `D`. This happens if `ptsR>0`. If that is not the case then we move the `D` back to the queue. We do this till the time `Q` has only `D`s or only `R`s.

 {% highlight java %} 
class Solution {
    public String predictPartyVictory(String senate) 
    {
        Queue<Character> Q = new LinkedList<Character>();
        int ctrD=0, ctrR=0;
        for (int i=0; i<senate.length(); i++)
        {
            char ch = senate.charAt(i);
            if (ch=='D') ctrD++;
            else if (ch=='R') ctrR++;
            Q.add(ch);
        }
        int ptsD=0, ptsR=0;
        while (Q.size()>1)
        {
            char ch = Q.poll();
            if (ch=='D') if (ptsR>0) {ptsR--; ctrD--;} else {Q.add(ch); ptsD++;}
            if (ch=='R') if (ptsD>0) {ptsD--; ctrR--;} else {Q.add(ch); ptsR++;}
            if (ctrD==0 || ctrR==0) break;
        }
        return ((Q.poll()=='R')?"Radiant":"Dire");
    }
}
 {% endhighlight %}
TC: $O(n)$, SC: $O(1)$