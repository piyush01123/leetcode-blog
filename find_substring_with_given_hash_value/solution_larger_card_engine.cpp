class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int hashValue) {
        long long cur=0, pk=1, hash=0;
        int n=s.length(), res=0;
        for (int i=n-1; i>=0; i--)
        {
            hash = (hash * p + s[i]-'a'+1) % m;
            if (i+k>=n) pk = pk * p % m;    
            else hash = (hash - (s[i+k]-'a'+1) * pk%m )%m;
            hash = (hash+m)%m; //to make it non negative
            if (hash==hashValue) res=i; 
        }
        return s.substr(res, k);
    }
};