Maintain a stack of (char, frequency) pair.
Here is how it works for a test case.
#### Input:
```
s = "deeedbbcccbdaa", k = 3
```
#### Dry run:
First column is where you are at. Second column is the stack at that time
```
d : [["d", 1]] 
e : [["d", 1], ["e", 1]] 
e : [["d", 1], ["e", 2]] 
e : [["d", 1]] #You popped here
d : [["d", 2]] 
b : [["d", 2], ["b", 1]] 
b : [["d", 2], ["b", 2]] 
c : [["d", 2], ["b", 2], ["c", 1]] 
c : [["d", 2], ["b", 2], ["c", 2]] 
c : [["d", 2], ["b", 2]] #You popped here
b : [["d", 2]] #You popped here
d : [] #You popped here
a : [["a", 1]] 
a : [["a", 2]] 
```
#### Answer:
Just join the elements in stack:
```
"aa"
```

Now we are ready to code!
# Code:
```
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> H;
        for (char ch: s)
        {
            if (H.empty() || H.top().first!=ch) H.push({ch,1});
            else
            {
                H.top().second++;
                if (H.top().second==k) H.pop();
            }
        }
        string t="";
        while (!H.empty())
        {
            auto p=H.top(); 
            t+=string(p.second,p.first);
            H.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};
```