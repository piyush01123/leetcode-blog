class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length(), i=0, res=0;
        vector<int> A(3,0);
        for (int j=0; j<n; j++)
        {
            A[s[j]-'a']++;
            while (*min_element(A.begin(),A.end())>0)
            {
                A[s[i]-'a']--;
                i++;
            }
            res += i;
        }
        return res;
    }
};