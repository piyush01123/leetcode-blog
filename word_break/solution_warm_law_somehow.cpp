class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> validity(n+1, false);
        validity[0] = true;
        for (int i=1; i<=n; i++)
        {
            // cout<<"I="<<i<<endl;
            bool isValid = false;
            for (int j=0; j<i; j++)
            {
                // cout <<"J="<<j<<' '<<s.substr(j,i-j)<<endl;
                if (validity[j] && find(wordDict.begin(), wordDict.end(), s.substr(j,i-j))!=wordDict.end())
                {isValid=true; break;}
            }
            validity[i] = isValid;
        }
        return validity[n];
    }
};