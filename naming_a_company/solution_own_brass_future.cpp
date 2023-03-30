class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        long long res = 0;
        vector<unordered_set<string>> ideaSet(26, unordered_set<string>{});
        for(string idea: ideas) ideaSet[idea[0]-'a'].insert(idea.substr(1));
        for (int i=0; i<26; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                int common=0;
                for(string idea: ideaSet[j]) common+=ideaSet[i].count(idea);
                int n1 = ideaSet[i].size()-common, n2=ideaSet[j].size()-common;
                res += 2LL*n1*n2;
            }
        }
        return res;
    }
};