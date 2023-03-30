class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        // decrease 0,2,4,6
        int n = nums.size(), res1 = 0, res2=0;
        for (int i=0; i<n; i+=2)
        {
            int x = nums[i];
            int j=i-1, k=i+1;
            int y = (j<0)?INT_MAX:nums[j];
            int z = (k>=n)?INT_MAX:nums[k];
            if(x<min(y,z)) 
                continue;
            else
                res1 += (x-min(y,z)+1);
            
        }
        for (int i=1; i<n; i+=2)
        {
            int x = nums[i];
            int j=i-1, k=i+1;
            int y = (j<0)?INT_MAX:nums[j];
            int z = (k>=n)?INT_MAX:nums[k];
            if(x<min(y,z)) 
                continue;
            else
                res2 += (x-min(y,z)+1);
            
        }
        return min(res1,res2);
    }
};

// 1,1->-1,1 or 1,-1
// -3,-5,5,-4