class Solution {
public:
    bool isPalindrome(string s)
    {
        int i=0, j=s.size()-1;
        while(i<j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    void dfs(string s, vector<string> &curr_list, vector<vector<string>> &res, int start)
    {
        if (start>=s.size()) res.push_back(curr_list);
        for (int end=start; end<s.size(); end++) 
        {
            if (isPalindrome(s.substr(start, end-start+1)))
            {
                curr_list.push_back(s.substr(start, end-start+1));
                dfs(s, curr_list, res, end+1);
                curr_list.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr_list;
        dfs(s, curr_list, res, 0);
        return res;
    }
};