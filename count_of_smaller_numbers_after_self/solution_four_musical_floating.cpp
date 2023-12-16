#define pii pair<int,int>
class Solution {
    vector<int>res;
public:
    void mergeSort(vector<pii>&A, int lo, int hi)
    {
        if (lo==hi) return;
        int mid = lo + (hi-lo)/2;
        mergeSort(A, lo, mid);
        mergeSort(A,mid+1,hi);
        vector<pii> L(A.begin()+lo,A.begin()+mid+1);
        vector<pii> R(A.begin()+mid+1,A.begin()+hi+1);
        int n1=L.size(), n2=R.size(), i=0, j=0, k=lo, ctr=0;
        while(i<n1 && j<n2) 
        {
            if(L[i].first<=R[j].first) 
            {
                res[L[i].second] += ctr;
                A[k++]=L[i++];
            } 
            else
            {
                ctr++;
                A[k++]=R[j++];
            }
        }
        while(i<n1) 
        {
            res[L[i].second] += ctr;
            A[k++]=L[i++];
        }
        while(j<n2) A[k++]=R[j++];
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        res.resize(n,0);
        vector<pii> pairs;
        for(int i=0; i<n; i++) pairs.push_back({nums[i],i});
        mergeSort(pairs,0,n-1);
        for(auto k: pairs) cout<<k.first<<',';
        return res;        
    }
};