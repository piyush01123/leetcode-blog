class Solution {
public:
    bool isPalindrome(string word)
    {
        for (int i=0, j=word.size()-1; i<j; i++, j--) if (word[i]!=word[j]) return false;
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (string word: words) if (isPalindrome(word) )return word;
        return "";
    }
};