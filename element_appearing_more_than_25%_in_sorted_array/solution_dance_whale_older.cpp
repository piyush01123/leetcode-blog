class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int ctr=1, n=arr.size();
        if (n==1) return arr[0];
        for(int i=1; i<n; i++)
        {
            if(arr[i]==arr[i-1]) ctr++;
            else ctr=1;
            if(ctr>n/4) return arr[i];
        }        
        return -1;
    }
};