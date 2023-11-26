class Solution {
public:
    bool checkAS(vector<int>&nums, int minVal, int maxVal, int li, int ri)
    {
        if (minVal==maxVal) return true;
        if ((maxVal-minVal)%(ri-li)) return false;
        int diff = (maxVal-minVal)/(ri-li);
        vector<bool> arithSub(ri-li+1,false);
        for(int j=li; j<=ri; j++) 
        {
            if((nums[j]-minVal)%diff>0 || arithSub[(nums[j]-minVal)/diff]) return false;
            else arithSub[(nums[j]-minVal)/diff] = true;
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> res;
        for (int i=0; i<l.size(); i++)
        {
            int li = l[i], ri = r[i];
            auto ptrs = minmax_element(nums.begin()+li, nums.begin()+ri+1);
            int minVal = *(ptrs.first), maxVal = *(ptrs.second);
            res.push_back(checkAS(nums, minVal, maxVal, li, ri));
        }        
        return res;
    }
};