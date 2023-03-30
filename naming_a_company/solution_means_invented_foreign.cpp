class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long res = 0;
        unordered_set<string> ideaSet(ideas.begin(),ideas.end());
        vector<vector<int>>freq_table(26,vector<int>(26,0));
        for (string idea: ideas)
        {
            for(char ch='a'; ch<='z'; ch++)
            {
                string namePart = string(1,ch)+idea.substr(1);
                if(!ideaSet.count(namePart))
                    freq_table[idea[0]-'a'][ch-'a']++;
            }
        }
        for (int i=0; i<26; i++)
            for (int j=i+1; j<26; j++)
                res += 2LL*freq_table[i][j]*freq_table[j][i];
        return res;
    }
};