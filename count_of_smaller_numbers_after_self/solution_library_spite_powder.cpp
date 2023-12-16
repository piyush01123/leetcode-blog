#define pii pair<int,int>
class Solution {
    vector<int>res;
public:
    void mergeSort(vector<pii>&A, int lo, int hi)
    {
        if (lo==hi-1) return;
        int mid = lo + (hi-lo)/2;
        mergeSort(A, lo, mid);
        mergeSort(A,mid,hi);
        vector<pii> L(A.begin()+lo,A.begin()+mid);
        vector<pii> R(A.begin()+mid,A.begin()+hi);
        int n1=L.size(), n2=R.size(), i=0, j=0, k=lo;
        while(i<n1 && j<n2) if(L[i].first>R[j].first) 
        {
            res[L[i].second]+=(n2-j); 
            A[k++]=L[i++];
        }  else A[k++]=R[j++];
        while(i<n1) A[k++]=L[i++];
        while(j<n2) A[k++]=R[j++];
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        res.resize(n,0);
        vector<pii> pairs;
        for(int i=0; i<n; i++) pairs.push_back({nums[i],i});
        mergeSort(pairs,0,n);
        // for(auto k: pairs) cout<<k.first<<',';
        return res;        
    }
};