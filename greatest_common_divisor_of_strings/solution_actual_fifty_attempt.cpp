class Solution {
public:
    int gcd(int a, int b)
    {
        if (a%b==0) return b;
        return gcd(b, a%b);
    }
    string gcdOfStrings(string str1, string str2) 
    {
        if (str1+str2 != str2+str1) return "";
        return str1.substr(0,gcd(str1.length(), str2.length()));
    }
};