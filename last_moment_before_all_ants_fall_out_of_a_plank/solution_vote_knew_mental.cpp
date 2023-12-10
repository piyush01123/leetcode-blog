class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int a = left.empty() ? -1 : *max_element(left.begin(),left.end());
        int b = right.empty() ? -1 : *min_element(right.begin(),right.end());
        if (a==-1) return n-b;
        if (b==-1) return a;
        return max(a, n-b);
    }
};