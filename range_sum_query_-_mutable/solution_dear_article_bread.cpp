void build(vector<int>&A, vector<int>&tree, int node, int lo, int hi)
{
	if (lo==hi){tree[node]=A[lo];return;}
	int mid = lo + (hi-lo)/2;
	build(A, tree, 2*node+1, lo, mid);
	build(A, tree, 2*node+2, mid+1, hi);
	tree[node] = tree[2*node+1]+tree[2*node+2];
}
int query(vector<int>&tree, int node, int lo, int hi, int qlo, int qhi)
{
	if (qhi<lo || qlo>hi) return 0;
	if (qlo<=lo && qhi>=hi) return tree[node];
	int mid = lo+(hi-lo)/2;
	return query(tree, 2*node+1, lo, mid, qlo, qhi) + \
		   query(tree, 2*node+2, mid+1,hi,qlo, qhi);
}

void supdate(vector<int>&tree, int node, int lo, int hi, int index, int value)
{
	if (lo==hi) {tree[node] = value; return;}
	int mid = lo + (hi-lo)/2;
	if (index<=mid) supdate(tree, 2*node+1, lo, mid, index, value);
	else if (index>mid) supdate(tree, 2*node+2, mid+1, hi, index, value);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}


class NumArray {
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(4*n);
        build(nums, tree, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        supdate(tree, 0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(tree, 0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */