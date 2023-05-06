class Solution {
public:
    int addMinimum(string word) 
    {
        int n=word.length(), i=0, res=0;
        while (i<n)
        {
            int ctr = 0;
            if (word[i]=='a'){ctr++; i++;}
            if (word[i]=='b'){ctr++; i++;}
            if (word[i]=='c'){ctr++; i++;}
            res += (3-ctr);
        }
        return res;
    }
};