class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_set<string> words(dictionary.begin(),dictionary.end());
        int n = s.length();
        vector<int> res(n+1,0);
        for (int i=1; i<=n; i++)
        {
            res[i] = res[i-1]+1;
            for (int j=0; j<i; j++) if (words.count(s.substr(j,i-j)))
                res[i] = min(res[i], res[j]);
        }
        // for(int k:res)cout<<k<<',';cout<<endl;
        return res[n];
    }
};


/*
0123456789
 leetscode
0123012341
*/