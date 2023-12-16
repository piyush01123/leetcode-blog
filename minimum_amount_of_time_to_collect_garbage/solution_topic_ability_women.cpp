class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int res=0, g_last=-1, m_last=-1, p_last=-1;
        for (int i=0; i<garbage.size(); i++)
        {
            int g=0, m=0, p=0;
            for (char ch: garbage[i])
            {
                if (ch=='G') g++;
                if (ch=='M') m++;
                if (ch=='P') p++;
                res++;
            }
            if (g>0) g_last=i;
            if (m>0) m_last=i;
            if (p>0) p_last=i;
        }
        if (g_last>=0) for(int i=0; i<g_last; i++) res+=travel[i];
        if (m_last>=0) for(int i=0; i<m_last; i++) res+=travel[i];
        if (p_last>=0) for(int i=0; i<p_last; i++) res+=travel[i];
        return res;
    }
};