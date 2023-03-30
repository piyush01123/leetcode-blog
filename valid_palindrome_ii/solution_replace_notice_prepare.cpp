
bool isPalindrome(string s, int start, int end)
{
    while (start<end)
    {
        if (s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}


class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        if (isPalindrome(s,0,n-1)) return true;
        int i=0, j=n-1;
        while (i<n && j>=0 && s[i]==s[j])
        {
            i++;
            j--;
        }
        return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
    }
};