class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length(), tl = t.length(), i=0, j=0;
        while (i<sl)
        {
            if (j==tl) return false;
            if (s[i]==t[j]) i++;
            j++;
        }
        return true;
    }
};