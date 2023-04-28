class Solution {
public:
    int addMinimum(string word) 
    {
        int n = word.length(), i=0, res=0;
        while (i<n)
        {
            if (i+2<n && word[i]=='a' & word[i+1]=='b' & word[i+2]=='c')
                i+= 3;
            else if (i+1<n && word[i]=='a' && word[i+1]=='b') 
                {res+=1; i+=2;}
            else if (i+1<n && word[i]=='b' && word[i+1]=='c') 
                {res+=1; i+=2;}
            else if (i+1<n && word[i]=='a' && word[i+1]=='c') 
                {res+=1; i+=2;}
            else {res+=2; i+=1;}
        }
        return res;
    }
};