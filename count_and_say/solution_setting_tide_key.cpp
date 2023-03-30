class Solution {
public:
    string say(string num)
    {
        int i=0;
        string res = "";
        while(i<num.length())
        {
            int j=i;
            while(j<num.length()&&num[j]==num[i]) j++;
            res.push_back(j-i+'0');
            res.push_back(num[i]);
            i = j;
        }
        return res;
    }
    string countAndSay(int n) 
    {
        vector<string> vec(n);
        vec[0] = "1";
        for (int i=1; i<n; i++)
            vec[i] = say(vec[i-1]);
        return vec[n-1];
    }
};