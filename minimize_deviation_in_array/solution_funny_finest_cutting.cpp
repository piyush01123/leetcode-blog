class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        priority_queue<int> pq;
        int m=INT_MAX, res=INT_MAX;
        for (int n: nums)
        {
            if (n%2) n*=2;
            pq.push(n);
            m = min(m, n);
        }
        while (pq.top()%2==0)
        {
            res = min(res, pq.top()-m);
            m = min(m, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res, pq.top()-m);
    }
};

/*
4,2,10,20,6
4,2,10,5,6
4,2,5,5,6
4,2,5,5,3

2,2,6,4
2,2,3,4
2,2,3,2

2,10,8
2,5,8
2,5,4

6,10
6,5

4,18,4,10
4,9,4,10
4,9,4,5
*/