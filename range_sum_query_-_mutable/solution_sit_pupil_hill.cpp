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

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */