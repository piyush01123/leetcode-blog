class SegmentTree
{
    public:
    vector<int> tree, A;
    SegmentTree(int n): tree(4*n, 0), A(n,0){}
    void update(int node, int lo, int hi, int index, int value)
    {
        if (lo==hi)
        {
            A[index] = value;
            tree[node] = 0;
            return;
        }
        int mid = lo + (hi-lo)/2;
        if (index<=mid) update(2*node+1, lo, mid, index, value);
        else update(2*node+2, mid+1, hi, index, value);
        tree[node] = tree[2*node+1] + tree[2*node+2] + (A[mid]==A[mid+1] && A[mid]>0);
        return;
    }
};

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries)
    {
        SegmentTree segTree = SegmentTree(n);
        vector<int> res;
        for (auto &query: queries)
        {
            int index=query[0], value=query[1];
            segTree.update(0, 0, n-1, index, value);
            res.push_back(segTree.tree[0]);
        }
        return res;
    }
};