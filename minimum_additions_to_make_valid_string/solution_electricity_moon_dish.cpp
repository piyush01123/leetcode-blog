class Solution {
public:
    int addMinimum(string word) 
    {
        char prev='d';
        int n=word.length(), lenby3=0;
        for (int i=0;  i<n; i++)
        {
            lenby3 += (word[i]<=prev);
            prev = word[i];
        }
        return 3*lenby3-word.length();
    }
};