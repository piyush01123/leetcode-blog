class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int pos1 = min_element(nums.begin(),nums.end())-nums.begin();
        int posn = max_element(nums.begin(),nums.end())-nums.begin();
        if (pos1<posn) return pos1+n-1-posn;
        return pos1+n-posn-2;
    }
};

/*
4,2,3,1
4,2,1,3
4,1,2,3
1,4,2,3
1,2,4,3
1,2,3,4
3+
*/