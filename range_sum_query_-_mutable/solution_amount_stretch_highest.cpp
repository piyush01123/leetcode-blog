class SegmentTree
{
    public:
    int n;
    vector<int> A;
    vector<int> tree;
    SegmentTree(){}
    void build(int node, int start, int end)
    {
        // cout<<"BUILD:"<<node<<','<<start<<','<<end<<endl;
        if (start==end){tree[node] = A[start]; return;}
        int mid = start + (end-start)/2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    SegmentTree(vector<int> vec)
    {
        n = vec.size();
        A = vec;
        tree = vector<int>(4*n, 0);
        build(0, 0, n-1);
    }
    void update(int node, int start, int end, int index, int value)
    {
        // cout<<"UPDATE:"<<node<<','<<start<<','<<end<<','<<index<<','<<value<<endl;
        if (start==end && end==index){tree[node]=value;return;}
        int mid = start + (end-start)/2;
        if (index<=mid)
            update(2*node+1, start, mid, index, value);
        else
            update(2*node+2, mid+1, end, index, value);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    int query(int node, int start, int end, int left, int right)
    {
        // cout<<"QUERY:"<<node<<','<<start<<','<<end<<','<<left<<','<<right<<endl;
        if (left>end || right<start) return 0;
        if (left<=start && right>=end) return tree[node];
        int mid = start + (end-start)/2;
        int q1 = query(2*node+1, start, mid, left, right);
        int q2 = query(2*node+2, mid+1, end, left, right);
        return q1+q2;
    }
    void ptree()
    {
        cout<<"TREE:";for(int item: tree)cout<<item<<',';cout<<endl;
    }
};

class NumArray {
public:
    SegmentTree stree;
    NumArray(vector<int>& nums) 
    {
        stree=SegmentTree(nums);
        // stree.ptree();
    }    
    void update(int idx, int val)
    {
        stree.update(0, 0, stree.n-1, idx, val);
        // stree.ptree();
    }
    int sumRange(int left, int right)
    {
        return stree.query(0,0,stree.n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */