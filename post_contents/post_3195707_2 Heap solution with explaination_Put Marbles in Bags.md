The question amounts to putting up `K-1` walls inside the `weights` array. The score is the sum of all the adjacent members of walls plus `weights[0]+weights[n-1]`.
For example consider the input `weights = [a,b,c,d,e,f,g,h,i], K=3` and if we put up walls like this: `a b c | d e f g |  h i`  then the score is `(a+c) + (d+g) + (h+i)` which can also be written as `(a+i) + (c+d) + (g+h)`.

Now we want to find the difference between minimum and maximum scores. Notice that the first and last elements will always be part of any score. So, we need not consider them to calculate the difference. We can use a max-heap and a min-heap to store the sum of all adjacent pairs. In our example, this will be `a+b, b+c, c+d, d+e, e+f, f+g, g+h, h+i`. Once we have constructed both the heaps, the maximum score is the sum of `K-1` largest numbers from max heap and the minimum score is the sum of `K-1` smallest numbers from the min heap (plus the first and last, but we are ignoring them because they occur in both). Their difference gives us the answer.
 
# Code
```
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size(), cur=weights[0];
        if(k==1 || n==k) return 0;
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for (int i=1; i<n; i++)
        {
            if (i>=2) cur -= weights[i-2];
            cur += weights[i];
            max_pq.push(cur);
            min_pq.push(cur);

        }
        long long res = 0;
        for (int i=0; i<k-1; i++)
        {
            res += max_pq.top();
            res -= min_pq.top();
            max_pq.pop();
            min_pq.pop();
        }
        return res;
    }
};
```

# Complexity
TC: $O(n + k\log(n))$, SC: $O(n)$

If you like this post, please upvote it!