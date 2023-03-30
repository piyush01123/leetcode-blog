class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> res;
        int n=s.length(), j=n-1;
        while (s[j]!=s[0]) j--;
        for (int i=0; i<=j; i++)
        {
            int jj=n-1;
            while (s[jj]!=s[i]) jj--;
            j = max(j,jj);
        }
        res.push_back(j+1);
        if (j<s.length()-1)
        {
            for (int len: partitionLabels(s.substr(j+1,n)))
                res.push_back(len);
        }
        return res;
    }
};