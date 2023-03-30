class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1, res=0;
        while (l<r)
        {
            int curr = min(height[l],height[r]) * (r-l);
            res = max(res, curr);
            if (height[r]>height[l]) l++;
            else r--;
        }
        return res;
    }
};