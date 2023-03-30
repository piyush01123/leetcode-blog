class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), res=0;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                // auto itl = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]);
                // auto itu = upper_bound(nums.begin(), nums.end(), nums[i]+nums[j]);
                // int posl=itl-nums.begin(), posu=itu-nums.begin();
                // cout << i << ' ' << j << ' ' << posl << ' ' << posu << endl;
                // // if (pos<n) res+=(n-pos);
                
                auto it = lower_bound(nums.begin(), nums.end(), nums[i]+nums[j]);
                int pos = it-nums.begin();
                if (pos-j-1>0) res+=(pos-j-1);
            }
        }
        return res;
    }
};