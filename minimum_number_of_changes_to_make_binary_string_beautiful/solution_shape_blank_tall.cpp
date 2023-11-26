class Solution {
public:
    int minChanges(string s) 
    {
        int n = s.length(), cur=1, res=0;
        vector<int> A;
        for(int i=1; i<n; i++) if(s[i]==s[i-1]) cur++; else{A.push_back(cur); cur=1;}
        A.push_back(cur);
        bool curOdd = false;
        for(int i=0; i<A.size(); i++)
        {
            if (A[i]%2)
            {
                if(curOdd)
                {
                    res++;
                    curOdd = false;
                }
                else curOdd = true;
            } else if (curOdd) res++;
        }
        return res;        
    }
};