class Solution {
public:
    bool isNumber(string s)
    {
        auto it = s.begin();
        if (*it=='-')++it;
        while (it != s.end() && isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
    int calPoints(vector<string>& ops) {
        vector<int> score;
        for (string s: ops)
        {
            if (isNumber(s)) score.push_back(stoi(s));
            else if (s=="C") score.pop_back();
            else if (s=="D") score.push_back(score.back()*2);
            else if (s=="+") score.push_back(accumulate(score.end()-2,score.end(),0));
        }
        return accumulate(score.begin(),score.end(),0);
    }
};