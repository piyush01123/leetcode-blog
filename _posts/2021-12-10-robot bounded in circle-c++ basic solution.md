---
layout: mypost
title: "Robot Bounded In Circle - C++ Basic solution"
tags: ["Math", "String", "Simulation", "Medium"]
---
# Problem Statement:
<p>On an infinite plane, a robot initially stands at <code>(0, 0)</code> and faces north. Note that:</p>

<ul>
	<li>The <strong>north direction</strong> is the positive direction of the y-axis.</li>
	<li>The <strong>south direction</strong> is the negative direction of the y-axis.</li>
	<li>The <strong>east direction</strong> is the positive direction of the x-axis.</li>
	<li>The <strong>west direction</strong> is the negative direction of the x-axis.</li>
</ul>

<p>The robot can receive one of three instructions:</p>

<ul>
	<li><code>&quot;G&quot;</code>: go straight 1 unit.</li>
	<li><code>&quot;L&quot;</code>: turn 90 degrees to the left (i.e., anti-clockwise direction).</li>
	<li><code>&quot;R&quot;</code>: turn 90 degrees to the right (i.e., clockwise direction).</li>
</ul>

<p>The robot performs the <code>instructions</code> given in order, and repeats them forever.</p>

<p>Return <code>true</code> if and only if there exists a circle in the plane such that the robot never leaves the circle.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> instructions = &quot;GGLLGG&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> The robot is initially at (0, 0) facing the north direction.
&quot;G&quot;: move one step. Position: (0, 1). Direction: North.
&quot;G&quot;: move one step. Position: (0, 2). Direction: North.
&quot;L&quot;: turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
&quot;L&quot;: turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
&quot;G&quot;: move one step. Position: (0, 1). Direction: South.
&quot;G&quot;: move one step. Position: (0, 0). Direction: South.
Repeating the instructions, the robot goes into the cycle: (0, 0) --&gt; (0, 1) --&gt; (0, 2) --&gt; (0, 1) --&gt; (0, 0).
Based on that, we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> instructions = &quot;GG&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> The robot is initially at (0, 0) facing the north direction.
&quot;G&quot;: move one step. Position: (0, 1). Direction: North.
&quot;G&quot;: move one step. Position: (0, 2). Direction: North.
Repeating the instructions, keeps advancing in the north direction and does not go into cycles.
Based on that, we return false.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> instructions = &quot;GL&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> The robot is initially at (0, 0) facing the north direction.
&quot;G&quot;: move one step. Position: (0, 1). Direction: North.
&quot;L&quot;: turn 90 degrees anti-clockwise. Position: (0, 1). Direction: West.
&quot;G&quot;: move one step. Position: (-1, 1). Direction: West.
&quot;L&quot;: turn 90 degrees anti-clockwise. Position: (-1, 1). Direction: South.
&quot;G&quot;: move one step. Position: (-1, 0). Direction: South.
&quot;L&quot;: turn 90 degrees anti-clockwise. Position: (-1, 0). Direction: East.
&quot;G&quot;: move one step. Position: (0, 0). Direction: East.
&quot;L&quot;: turn 90 degrees anti-clockwise. Position: (0, 0). Direction: North.
Repeating the instructions, the robot goes into the cycle: (0, 0) --&gt; (0, 1) --&gt; (-1, 1) --&gt; (-1, 0) --&gt; (0, 0).
Based on that, we return true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= instructions.length &lt;= 100</code></li>
	<li><code>instructions[i]</code> is <code>&#39;G&#39;</code>, <code>&#39;L&#39;</code> or, <code>&#39;R&#39;</code>.</li>
</ul>

# Solution:
After little bit of experimenting on paper, one can realize that the only situation that it does not land up at origin is if we do not end up on origin after one round and are also facing north.
The other two cases are:
- Ending up on origin: Obviously it is `true`
- Not ending up on origin but facing South/East/West: This is also true because after 2 rounds(South) or 4 rounds(East/West), we will again land at origin.

Now for implementation, we will use three variables:
- `a` for x-coordinate
- `b` for y-coordinate
- `c` for direction

All 3 are integers. One important thing to notice is that we can use `c` variable for direction as follows:
- If you see 'L',  increment c by 1
- If you see 'R', increment c by 3
- If you see 'G', do not change c

Further we can check which direction we are facing:
- `c%4=0` means North
- `c%4=1` means West
- `c%4=2` means South
- `c%4=3` means East


Now the logic is that:
- If you see G, find out which direction you are facing and modify the coordinates accordingly. This will change either a or b.
- If you see L or R, change the variable c as per rule given above. Variables a and b do not change in this case.

```
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int a=0,b=0,c=0;
        for(char ch: instructions)
        {
            if(ch=='G')
            {
                if(c%4==0)b++;
                if(c%4==1)a--;
                if(c%4==2)b--;
                if(c%4==3)a++;
            }
            if(ch=='L') c++;
            if(ch=='R') c+=3;
        }
        cout << a << ' ' << b << ' ' << c << endl;
        if(c%4==0 && (a!=0 || b!=0)) return false;
        return true;
    }
};
```