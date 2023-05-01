---
layout: mypost
title: "Range Sum Query - Mutable - Segment tree in C++ and Java"
tags: ["Array", "Design", "Binary Indexed Tree", "Segment Tree", "Java", "Medium"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code>, handle multiple queries of the following types:</p>

<ol>
	<li><strong>Update</strong> the value of an element in <code>nums</code>.</li>
	<li>Calculate the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> where <code>left &lt;= right</code>.</li>
</ol>

<p>Implement the <code>NumArray</code> class:</p>

<ul>
	<li><code>NumArray(int[] nums)</code> Initializes the object with the integer array <code>nums</code>.</li>
	<li><code>void update(int index, int val)</code> <strong>Updates</strong> the value of <code>nums[index]</code> to be <code>val</code>.</li>
	<li><code>int sumRange(int left, int right)</code> Returns the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> (i.e. <code>nums[left] + nums[left + 1] + ... + nums[right]</code>).</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;NumArray&quot;, &quot;sumRange&quot;, &quot;update&quot;, &quot;sumRange&quot;]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
<strong>Output</strong>
[null, 9, null, 8]

<strong>Explanation</strong>
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>0 &lt;= index &lt; nums.length</code></li>
	<li><code>-100 &lt;= val &lt;= 100</code></li>
	<li><code>0 &lt;= left &lt;= right &lt; nums.length</code></li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls will be made to <code>update</code> and <code>sumRange</code>.</li>
</ul>

# Solution:
**SegmentTree in C++**:
 {% highlight java %} 
class SegmentTree
{
    vector<int> tree;
public:
    SegmentTree(vector<int> &nums)
    {
        int n = nums.size();
        tree = vector<int>(4*n);
        build(nums, 0, 0, n-1);
    }
    void build(vector<int>&A, int node, int lo, int hi)
    {
        if (lo==hi){tree[node]=A[lo]; return;}
        int mid = lo + (hi-lo)/2;
        build(A, 2*node+1, lo, mid);
        build(A, 2*node+2, mid+1, hi);
        tree[node] = tree[2*node+1]+tree[2*node+2];
    }
    int query(int node, int lo, int hi, int qlo, int qhi)
    {
        if (qhi<lo || qlo>hi) return 0;
        if (qlo<=lo && qhi>=hi) return tree[node];
        int mid = lo+(hi-lo)/2;
        return query(2*node+1, lo, mid, qlo, qhi) + \
            query(2*node+2, mid+1,hi,qlo, qhi);
    }
    void update(int node, int lo, int hi, int index, int value)
    {
        if (hi<lo) return;
        if (lo==hi) {tree[node] = value; return;}
        int mid = lo + (hi-lo)/2;
        if (index<=mid) update(2*node+1, lo, mid, index, value);
        else if (index>mid) update(2*node+2, mid+1, hi, index, value);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
};

class NumArray {
    int N;
    SegmentTree segTree;
public:
    NumArray(vector<int>& nums): segTree(nums), N(nums.size()) {}
    
    void update(int index, int val) {
        segTree.update(0,0,N-1,index,val);
    }
    
    int sumRange(int left, int right) {
return segTree.query(0, 0, N-1, left, right);
    }
};
 {% endhighlight %}

**Segment tree in Java**:

 {% highlight java %} 
class SegmentTree
{
    int[] tree;
    SegmentTree(int[] A)
    {
        int n = A.length;
        tree = new int[4*n];
        build(A, 0, 0, n-1);
    }
    void build(int[] A, int node, int lo, int hi)
    {
        if (lo==hi){tree[node] = A[lo]; return;}
        int mid = lo+(hi-lo)/2;
        build(A, 2*node+1, lo, mid);
        build(A, 2*node+2, mid+1, hi);        
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    int query(int node, int lo, int hi, int qlo, int qhi)
    {
        if (qhi<lo || qlo>hi) return 0;
        if (qlo<=lo && qhi>=hi) return tree[node];
        int mid = lo + (hi-lo)/2;
        return query(2*node+1, lo, mid, qlo, qhi) + 
               query(2*node+2, mid+1, hi, qlo, qhi);
    }
    void update(int node, int lo, int hi, int index, int value)
    {
        if (lo==hi){tree[node] = value; return;}
        int mid = lo+(hi-lo)/2;
        if (index<=mid) update(2*node+1, lo, mid, index, value);
        if (index>mid) update(2*node+2, mid+1, hi, index, value);
        tree[node] = tree[2*node+1]+tree[2*node+2];
    }
}

class NumArray {
    int N;
    SegmentTree segTree;
    public NumArray(int[] nums) {
        N = nums.length;
        segTree = new SegmentTree(nums);
    }
    
    public void update(int index, int val) {
        segTree.update(0,0,N-1,index,val);
    }
    
    public int sumRange(int left, int right) {
        return segTree.query(0,0,N-1,left,right);
    }
}
 {% endhighlight %}
We can also use segment tree without creating another class though it will be slightly inefficient (still AC though)
 {% highlight java %} 
void build(vector<int>&A, vector<int>&tree, int node, int lo, int hi)
{
	if (lo==hi){tree[node]=A[lo];return;}
	int mid = lo + (hi-lo)/2;
	build(A, tree, 2*node+1, lo, mid);
	build(A, tree, 2*node+2, mid+1, hi);
	tree[node] = tree[2*node+1]+tree[2*node+2];
}
int query(vector<int>&tree, int node, int lo, int hi, int qlo, int qhi)
{
	if (qhi<lo || qlo>hi) return 0;
	if (qlo<=lo && qhi>=hi) return tree[node];
	int mid = lo+(hi-lo)/2;
	return query(tree, 2*node+1, lo, mid, qlo, qhi) + \
		   query(tree, 2*node+2, mid+1,hi,qlo, qhi);
}

void supdate(vector<int>&tree, int node, int lo, int hi, int index, int value)
{
	if (lo==hi) {tree[node] = value; return;}
	int mid = lo + (hi-lo)/2;
	if (index<=mid) supdate(tree, 2*node+1, lo, mid, index, value);
	else if (index>mid) supdate(tree, 2*node+2, mid+1, hi, index, value);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}


class NumArray {
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(4*n);
        build(nums, tree, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        supdate(tree, 0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(tree, 0, 0, n-1, left, right);
    }
};
 {% endhighlight %}