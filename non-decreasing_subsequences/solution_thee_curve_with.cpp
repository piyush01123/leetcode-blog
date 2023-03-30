class Solution {
public:
    bool isValid(vector<int>&vec)
    {
        if (vec.size()<2) return false;
        for (int i=1; i<vec.size(); i++) if(vec[i]<vec[i-1]) return false;
        return true;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        set<vector<int>> A;
        int n = nums.size();
        for (int bm=1; bm<(1<<n); bm++)
        {
            vector<int> vec;
            for (int i=0; i<n; i++) if (((bm>>i)&1) == 1) vec.push_back(nums[i]);
            if (isValid(vec)) A.insert(vec);    
        }
        return vector<vector<int>>(A.begin(),A.end());
    }
};