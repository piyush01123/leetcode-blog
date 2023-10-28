class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        int cur=0, left=1, right=(1<<(n-1));
        for (int i=1;i<n;i++)
        {
            int mid = left + (right-left)/2;
            if (k<=mid) right=mid;
            else
            {
                left=mid+1;
                cur = 1^cur;
            }
        }
        return cur;
    }
};