class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int i=0, res=0; 
        while (i<colors.length())
        {
            int j=i, curSum=0, curMax=INT_MIN;
            while(j<colors.length() && colors[j]==colors[i])
            {
                curSum += neededTime[j];
                curMax = max(curMax, neededTime[j]);
                j++;
            }
            res += (curSum-curMax);
            i = j;
        }
        return res;
    }
};