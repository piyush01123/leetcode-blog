class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), prev=-1, res=0;
        for (int i=0; i<n; i++)
        {
            if(seats[i])
            {
                res = prev<0?i:max(res, (i-prev)/2);
                prev = i;
            }
        }
        res = max(res, n-1-prev);
        return res;
    }
};