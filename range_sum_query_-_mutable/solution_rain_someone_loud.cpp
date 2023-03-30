class NumArray {
    vector<int> segment_tree;
    vector<int> A;
    int n;
public:
    void build(int node, int start, int end)
    {
        if (start==end)
        {
            segment_tree[node] = A[start];
            return;
        }
        int mid = start + (end-start)/2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        segment_tree[node] = segment_tree[2*node+1]+segment_tree[2*node+2];
    }
    int query(int node, int start, int end, int left, int right)
    {
        if (left>end || right<start) return 0;
        if (left<=start && right>=end) return segment_tree[node];
        int mid = start + (end-start)/2;
        int q1 = query(2*node+1, start, mid, left, right);
        int q2 = query(2*node+2, mid+1, end, left, right);
        return q1+q2;
    }
    void update(int node, int start, int end, int index, int value)
    {
        if (start==end && end==index)
        {
            A[index] = value;
            segment_tree[node] = value;
            return;
        }
        int mid = start + (end-start)/2;
        if (index<=mid)
            update(2*node+1, start, mid, index, value);
        else
            update(2*node+2, mid+1, end, index, value);
        segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
    }
     NumArray(vector<int>& nums) 
    {
        A = nums;
        n = nums.size();
        segment_tree = vector<int>(4*n, 0);
        build(0, 0, n-1);
    }
    
    void update(int index, int value) 
    {
        update(0, 0, n-1, index, value);
    }
    
    int sumRange(int left, int right) 
    {
        return query(0, 0, n-1, left, right);
        return -1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */