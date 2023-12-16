class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        int res=arr[0], ctr=0;
        for (int i=1; i<arr.size(); i++)
        {
            if (arr[i]>res)
            {
                res = arr[i];
                ctr = 1;
            }
            else ctr++;
            if (ctr==k) break;
        }
        return res;
    }
};