---
layout: mypost
title: "Solving Questions With Brainpower - Top-down and bottom-up DP with intuition"
tags: ["Array", "Dynamic Programming", "C++", "Java", "Recursion", "Memoization", "Medium"]
---
# Problem Statement:
<p>You are given a <strong>0-indexed</strong> 2D integer array <code>questions</code> where <code>questions[i] = [points<sub>i</sub>, brainpower<sub>i</sub>]</code>.</p>

<p>The array describes the questions of an exam, where you have to process the questions <strong>in order</strong> (i.e., starting from question <code>0</code>) and make a decision whether to <strong>solve</strong> or <strong>skip</strong> each question. Solving question <code>i</code> will <strong>earn</strong> you <code>points<sub>i</sub></code> points but you will be <strong>unable</strong> to solve each of the next <code>brainpower<sub>i</sub></code> questions. If you skip question <code>i</code>, you get to make the decision on the next question.</p>

<ul>
	<li>For example, given <code>questions = [[3, 2], [4, 3], [4, 4], [2, 5]]</code>:

	<ul>
		<li>If question <code>0</code> is solved, you will earn <code>3</code> points but you will be unable to solve questions <code>1</code> and <code>2</code>.</li>
		<li>If instead, question <code>0</code> is skipped and question <code>1</code> is solved, you will earn <code>4</code> points but you will be unable to solve questions <code>2</code> and <code>3</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the <strong>maximum</strong> points you can earn for the exam</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> questions = [[3,2],[4,3],[4,4],[2,5]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= questions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>questions[i].length == 2</code></li>
	<li><code>1 &lt;= points<sub>i</sub>, brainpower<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

# Solution:
For ease of understanding, let us start with a baseline solution which uses recursion. It fails for heavy test cases but still passes for toy tests given in problem description. The logic is simple: We can either choose to solve the current question and accumulate its points (and then skip the next few) or skip the current question. The answer is the maximum of both cases. 
 {% highlight java %} 
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions, int start=0)
    {
        if (start>=questions.size()) return 0;
        int points = questions[start][0], skips = questions[start][1];
        int a = points + mostPoints(questions, start+skips+1);
        int b = mostPoints(questions, start+1);
        return max(a,b);
    }
};
 {% endhighlight %}

To pass larger tests, we will need to add memoization. Notice that we may be doing repititive calculation in baseline solution. So, to avoid that we simple store the solutions in an array `memo` and check this array everytime and return from `memo` without doing calculation whenever possible. Let us also use `long long` dtype for `memo`.
 {% highlight java %} 
class Solution {
    vector<long long> memo;
public:
    long long mostPoints(vector<vector<int>>& questions, int start=0)
    {
        if (start>=questions.size()) return 0;
        if (start==0){memo = vector<long long>(questions.size(),-1);}
        if (memo[start]!=-1) return memo[start];
        int points = questions[start][0], skips = questions[start][1];
        long long a = (long long)points + mostPoints(questions, start+skips+1);
        long long b = mostPoints(questions, start+1);
        return memo[start] = max(a,b);
    }
};
 {% endhighlight %}
This gives us an AC with flying colors. \uD83D\uDE80

We can also use bottom-up DP to solve this problem. For this we start with an array filled with zeroes and traverse the  `questions` array in reverse. While traversal, we use the same logic of maximum of taking points + skipping or not taking each entry.
 {% highlight java %} 
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long> dp(n);
        for (int i=n-1; i>=0; i--)
        {
            int points = questions[i][0], skips = questions[i][1];
            long long a = (i+skips+1<n)?dp[i+skips+1]:0;
            long long b = (i+1<n)?dp[i+1]:0;
            dp[i] = max(a+points, b);
        }
        return dp[0];
    }
};
 {% endhighlight %}

This also gives us AC. Now, if you are a java kind of person, here is the java version of the last solution.
 {% highlight java %} 
class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long dp[] = new long[n];
        for(int i=n-1; i>=0; i--)
        {
            int points = questions[i][0], skips = questions[i][1];
            long a = (i+skips+1<n)?dp[i+skips+1]:0;
            long b = (i+1<n)?dp[i+1]:0;
            dp[i] = Math.max(a+(long)points, b);
        }
        return dp[0];
    }
}
 {% endhighlight %}
To write the memoized recursion solution in java, I will need to write a separate helper function as passing `start=0` in argument is not possible in java ([ref](https://stackoverflow.com/questions/997482/does-java-support-default-parameter-values)), so hopefully you can do that yourself.

*Complexity*: TC and SC of all solutions is $O(n)$.

**\uD83D\uDE80Upvote\uD83D\uDE80 if you liked my post.**