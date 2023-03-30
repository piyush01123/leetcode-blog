class Solution {
public:
    int lengthLongestPath(string input) 
    {
        stringstream ss(input);
        string line;
        vector<string> lines;
        while (getline(ss, line, '\n'))
            lines.push_back(line);
        stack<pair<int,int>> stk;
        int res=0;
        for (auto &line: lines)
        {
            int tabs=0;
            while (line[tabs]=='\t') tabs++;
            // cout<<tabs<<','<<string(line.begin()+tabs, line.end())<<endl;
            while (!stk.empty() && tabs<=stk.top().first) stk.pop();
            int cur = (stk.empty() ? line.length() : stk.top().second+1+line.length()-tabs);
            stk.push({tabs, cur});
            if (find(line.begin(),line.end(),'.')!=line.end()) res = max(res,cur);
            // cout<<line<<','<<tabs<<','<<cur<<','<<res<<endl;
        }
        return res;
    }
};

// 0,3
// 0,3  1,11
// 0,3  1,11
// 0,3  1,11 2,20

// dir/subdir2/file.ext