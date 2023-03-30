class Solution {
public:
    bool twoChars(string s, int n)
    {
        for (int i=0; i<n/2; i++)
            if (s[i]!='a' || s[n-1-i]!='a') return false;
        return s[n/2] != 'a';
    }
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        string orig = palindrome;
        if (n==1) return "";
        int i=0;
        while (i<n && palindrome[i]=='a') i++;
        if (i==n || (n%2==1 && twoChars(palindrome,n))) palindrome[n-1] = 'b';
        else
            palindrome[i] = 'a';
        // if (isPal(palindrome))
        // {
        //     palindrome = orig;
        //     palindrome[n-1]
        // }
        return palindrome;
    }
};