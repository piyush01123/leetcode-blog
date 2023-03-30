class Solution {
public:
    string reverseVowels(string s) 
    {
        unordered_set<char>vowels{'a','e','i','o','u','A','E','I','O','U'};
        int lo=0, hi=s.length()-1;
        while (lo<hi)
        {
            while(lo<s.length() && !vowels.count(s[lo])) lo++;
            while (hi>=0 && !vowels.count(s[hi])) hi--;
            if (lo<hi) swap(s[lo++],s[hi--]);
        }
        return s;
    }
};