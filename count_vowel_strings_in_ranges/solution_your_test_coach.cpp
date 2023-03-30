class Solution {
public:
    bool valid(string word)
    {
        unordered_set<char> vowels {'a','e','i','o','u'};
        char s=word[0], e=word[word.length()-1];
        return vowels.count(s) && vowels.count(e);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        int n=words.size();
        vector<int> cumsum(n+1,0), res(queries.size(),0);
        for(int i=0; i<n; i++) cumsum[i+1]=cumsum[i] + (1?valid(words[i]):0);
        for (int i=0; i<queries.size(); i++)
        {
            int l=queries[i][0], r=queries[i][1];
            res[i] = cumsum[r+1]-cumsum[l];
        }
        return res;
    }
};