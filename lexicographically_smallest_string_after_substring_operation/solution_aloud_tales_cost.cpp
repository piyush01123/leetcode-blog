class Solution {
public:
    string operate(string s, int start, int end)
    {
        for(int i=start; i<=end; i++) if(s[i]=='a')s[i]='z'; else s[i]=s[i]-1;
        return s;
    }
    string smallestString(string s) 
    {
        int n=s.length();
        int i=0;
        while(i<n && s[i]!='a')i++;
        if(i==n) return operate(s,0,n-1);
        if(i>0) return operate(s,0,i-1);
        while(i<n && s[i]=='a') i++;
        if (i==n) return operate(s,n-1,n-1);
        int j=i;
        while(j<n && s[j]!='a') j++;
        return operate(s,i,j-1);
    }
};