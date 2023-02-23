# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Monotonic stack will be very useful here because we need to keep track of length of directory at current depth.

# Approach
<!-- Describe your approach to solving the problem. -->
We will maintain the stack of `(depth, length of path)` and for each entry, we will keep popping from stack till we are at the correct depth.
Example 1:
```
dir: [(0,3)]
	subdir1: [(0,3)(1,11)]
	subdir2: [(0,3)(1,11)]
		file.ext: [(0,3)(1,11)(2,20)]
```
Example 2:
```
dir: [(0,3)]
	subdir1: [(0,3)(1,11)]
		file1.ext: [(0,3)(1,11)(2,21)]
		subsubdir1: [(0,3)(1,11)(2,22)]
	subdir2: [(0,3)(1,11)]
		subsubdir2: [(0,3)(1,11)(2,22)]
			file2.ext: [(0,3)(1,11)(2,22)(3,32)]
```
# Complexity
- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int lengthLongestPath(string input) 
    {
        stringstream ss(input);
        string line;
        vector<string> lines;
        while (getline(ss, line, "\
")) lines.push_back(line);
        stack<pair<int,int>> stk;
        int res=0;
        for (auto &line: lines)
        {
            int tabs=0;
            while (line[tabs]=="	") tabs++;
            while (!stk.empty() && tabs<=stk.top().first) stk.pop();
            int cur = (stk.empty() ? line.length() : stk.top().second+1+line.length()-tabs);
            stk.push({tabs, cur});
            if (find(line.begin(),line.end(),".")!=line.end()) res = max(res,cur);
        }
        return res;
    }
};
```