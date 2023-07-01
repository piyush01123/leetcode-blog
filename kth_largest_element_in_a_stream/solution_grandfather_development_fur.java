class KthLargest 
{
    PriorityQueue<Integer> pq;
    int K;
    public KthLargest(int k, int[] nums) 
    {
        K = k;
        pq = new PriorityQueue<Integer>();
        for (int num: nums) add(num);
    }
    
    public int add(int val) 
    {
        pq.add(val);
        if (pq.size()>K) pq.remove();
        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */