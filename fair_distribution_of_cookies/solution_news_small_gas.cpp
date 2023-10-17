class Solution {
    int res = INT_MAX;
public:
    void distribute(vector<int>&cookies, vector<int>&distribution, int cur, int k)
    {
        if(cur==cookies.size()) 
        {
            res=min(res, *max_element(distribution.begin(),distribution.end())); 
            return;
        }
        for(int i=0; i<k; i++)
        {
            distribution[i] += cookies[cur];
            distribute(cookies, distribution, cur+1, k);
            distribution[i] -= cookies[cur];
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int> distribution(k,0);
        distribute(cookies, distribution, 0, k);
        return res;
    }
};