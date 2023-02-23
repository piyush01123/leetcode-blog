The idea is to walk till centre and stop if you do not see "a". If you have reached centre than the input was either a string of type `aaxaa` (odd `len(input)` and centre is not `a`) or `aaa..a` (only a"s). In both cases, the solution is to replace last character with a "b".

```
class Solution {
public:
    string breakPalindrome(string palindrome) 
    {
        int n = palindrome.length(), i=0;
        if (n==1) return "";
        while (i<n/2 && palindrome[i]=="a") i++;
        if (i==n/2) palindrome[n-1] = "b";
        else palindrome[i] = "a";
        return palindrome;
    }
};
```