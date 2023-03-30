class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int max_vol = 0;
        int a=0,b=n-1;
        while(a<b)
        {
            int curr = min(height[b],height[a])*(b-a);
            if(curr>max_vol)max_vol=curr;
            if(height[a]>height[b])b--;
            else a++;
        }
        return max_vol;
    }
};