class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> answer(n+1, false);
        answer[0] = true;
        for (int i=1; i<=n; i++){
            bool q = false;
            for (int j=0; j<i; j++){
                string ss = s.substr(j,i-j);
                if (answer[j] && find(wordDict.begin(),wordDict.end(),ss) != wordDict.end()){
                    q = true;
                    break;
                }
            }
            answer[i] = q;
        }
        return answer[n];
    }
};