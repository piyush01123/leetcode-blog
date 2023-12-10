class SegTree
{
    vector<int> tree;
    vector<int> A;
public:
    SegTree(vector<int>input)
    {
        A = input;
        tree.resize(4*A.size(), 0);
    }
    void build(int node, int lo, int hi)
    {
        if(lo==hi){tree[node] = A[lo]; return;}
        int mid = lo + (hi-lo)/2;
        build(2*node+1, lo, mid);
        build(2*node+2, mid+1, hi);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    void update(int node, int lo, int hi, int index, int value)
    {
        if(lo==hi){tree[node]=value; return;}
        int mid = lo + (hi-lo)/2;
        if (index<=mid) update(2*node+1, lo, mid, index, value);
        else update(2*node+2, mid+1, hi, index, value);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    int query(int node, int lo, int hi, int qlo, int qhi)
    {
        if(qlo>hi || qhi<lo) return 0;
        if (qlo<=lo && qhi>=hi) return tree[node];
        int mid = lo + (hi-lo)/2;
        return query(2*node+1, lo, mid, qlo, qhi) + query(2*node+2, mid+1, hi, qlo, qhi);
    }
};

class NumArray {
    SegTree sTree;
    int n;
public:
    NumArray(vector<int>& nums) : sTree(nums)
    {
        n = nums.size();
        sTree.build(0, 0, n-1);
    }
    
    void update(int index, int val) 
    {
        sTree.update(0, 0, n-1, index, val);        
    }
    
    int sumRange(int left, int right) 
    {
        return sTree.query(0, 0, n-1, left, right);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */