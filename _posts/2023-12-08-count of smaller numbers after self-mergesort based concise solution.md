---
layout: mypost
title: "Count of Smaller Numbers After Self - MergeSort based concise solution"
tags: ["Array", "Binary Search", "Divide and Conquer", "Binary Indexed Tree", "Segment Tree", "Merge Sort", "Ordered Set", "C++", "Hard"]
---
# Problem Statement:
<p>Given an integer array <code>nums</code>, return<em> an integer array </em><code>counts</code><em> where </em><code>counts[i]</code><em> is the number of smaller elements to the right of </em><code>nums[i]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,2,6,1]
<strong>Output:</strong> [2,1,1,0]
<strong>Explanation:</strong>
To the right of 5 there are <b>2</b> smaller elements (2 and 1).
To the right of 2 there is only <b>1</b> smaller element (1).
To the right of 6 there is <b>1</b> smaller element (1).
To the right of 1 there is <b>0</b> smaller element.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1]
<strong>Output:</strong> [0]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [-1,-1]
<strong>Output:</strong> [0,0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

# Solution:
Here is a typical pseudocode for `mergeSort`:
 {% highlight cpp %} 
void mergeSort(vector<int>&A, int lo, int hi)
{
    int mid = lo+(hi-lo)/2;
    mergeSort(A,lo,mid);
    mergeSort(A,mid+1,hi);
    merge(); // merge logic in same or separate function
}
 {% endhighlight %}
Now in the merge logic we typically have this kind of logic:
 {% highlight cpp %} 
int i=0, j=0, k=0, n1=L.size(), n2=R.size();
vector<int> A(n1+n2);
while(i<n1 && j<n2) if(L[i]<=R[j]) A[k++]=L[i++]; else A[k++]=R[j++];
while(i<n1) A[k++]=L[i++];
while(j<n2) A[k++]=R[j++];
 {% endhighlight %}
This is for ascending order. For descending order, we just invert the inequality sign.

Now, for our question, if we store the indices with the values in `pair<int,int>` format, then we can modifty the `merge` logic to incorporate counting "Lower To the Right" logic.

This can be done in multiple ways as shown below:

Solution 1: Sort in ascending order
 {% highlight cpp %} 
#define pii pair<int,int>
class Solution {
    vector<int>res;
public:
    void mergeSort(vector<pii>&A, int lo, int hi)
    {
        if (lo==hi) return;
        int mid = lo + (hi-lo)/2;
        mergeSort(A, lo, mid);
        mergeSort(A,mid+1,hi);
        vector<pii> L(A.begin()+lo,A.begin()+mid+1);
        vector<pii> R(A.begin()+mid+1,A.begin()+hi+1);
        int n1=L.size(), n2=R.size(), i=0, j=0, k=lo, ctr=0;
        while(i<n1 && j<n2) 
        {
            if(L[i].first<=R[j].first) 
            {
                res[L[i].second] += ctr;
                A[k++]=L[i++];
            } 
            else
            {
                ctr++;
                A[k++]=R[j++];
            }
        }
        while(i<n1) 
        {
            res[L[i].second] += ctr;
            A[k++]=L[i++];
        }
        while(j<n2) A[k++]=R[j++];
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        res.resize(n,0);
        vector<pii> pairs;
        for(int i=0; i<n; i++) pairs.push_back({nums[i],i});
        mergeSort(pairs,0,n-1);
        for(auto k: pairs) cout<<k.first<<',';
        return res;        
    }
};
 {% endhighlight %}

Solution 2: Sort in descending order
 {% highlight cpp %} 
#define pii pair<int,int>
class Solution {
    vector<int>res;
public:
    void mergeSort(vector<pii>&A, int lo, int hi)
    {
        if (lo==hi) return;
        int mid = lo + (hi-lo)/2;
        mergeSort(A, lo, mid);
        mergeSort(A,mid+1,hi);
        vector<pii> L(A.begin()+lo,A.begin()+mid+1);
        vector<pii> R(A.begin()+mid+1,A.begin()+hi+1);
        int n1=L.size(), n2=R.size(), i=0, j=0, k=lo;
        while(i<n1 && j<n2) if(L[i].first>R[j].first) 
        {
            res[L[i].second]+=(n2-j); 
            A[k++]=L[i++];
        }  else A[k++]=R[j++];
        while(i<n1) A[k++]=L[i++];
        while(j<n2) A[k++]=R[j++];
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        res.resize(n,0);
        vector<pii> pairs;
        for(int i=0; i<n; i++) pairs.push_back({nums[i],i});
        mergeSort(pairs,0,n-1);
        // for(auto k: pairs) cout<<k.first<<',';
        return res;        
    }
};
 {% endhighlight %}