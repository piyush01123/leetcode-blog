```
class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>stk;
        unordered_map<char,char>map{{"(",")"},{"{","}"},{"[","]"}};
        for (char ch: s)
        {
            if (map.count(ch)) stk.push(ch);
            else
            {
                if (stk.empty() || map[stk.top()]!=ch)
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
```