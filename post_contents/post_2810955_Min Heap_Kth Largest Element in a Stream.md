Maintain the highest K elements in a min Heap. Then the root node is always the answer.
```
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums): k(k)
    {
        for (int n: nums) pq.push(n);
        while (pq.size()>k) pq.pop();
    }
    
    int add(int val) 
    {
        pq.push(val);
        while(pq.size()>k) pq.pop();
        return pq.top();
    }
};
```