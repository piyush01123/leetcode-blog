Example: `3[a2[c]]` 
After traversal we will have the stack `("",3),(a,2)` and have the string `c` as the current string. 
From the stack we pop `num` and then `prevString`.
```
curString = prevString + num*curString
```
 
C++ code:
```
class Solution {
public:
    string decodeString(string s) 
    {
        string curString="", curNum="";
        stack<string> stk;
        for (char ch: s)
        {
            if (ch=="[")
            {
                stk.push(curString);
                stk.push(curNum);
                curString = "";
                curNum = "";
            }
            else if (ch=="]")
            {
                int num = stoi(stk.top());
                stk.pop();
                string prevString = stk.top();
                stk.pop();
                string temp = prevString;
                for (int i=0;i<num;i++) 
                    temp += curString;
                curString = temp;
            }
            else if (isdigit(ch))
                curNum += ch;
            else
                curString += ch;
        }
        return curString;
    }
};
```