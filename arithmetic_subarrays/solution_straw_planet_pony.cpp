class Solution {
public:
    bool checkAS(vector<int>A, int left, int right)
    {
        if (right-left<=1) return true;
        sort(A.begin()+left,A.begin()+right+1);
        for(int i=left+1; i<=right; i++)
            if (A[i]-A[i-1] != A[left+1]-A[left]) return false;
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> res;
        for (int i=0; i<l.size(); i++)
        {
            int li = l[i], ri = r[i];
            res.push_back(checkAS(nums,li,ri));
        }
        return res;
    }
};