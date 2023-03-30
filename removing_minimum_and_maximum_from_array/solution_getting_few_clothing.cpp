class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minval=INT_MAX,maxval=-INT_MAX,amin=0,amax=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minval){minval=nums[i];amin=i;}
            if(nums[i]>maxval){maxval=nums[i];amax=i;}
        }
        int a = max(amin,amax)+1;
        int b = n-min(amin,amax);
        int c = min(amin+1,n-amin)+min(amax+1,n-amax);
        return min(min(a,b),c);
    }
};