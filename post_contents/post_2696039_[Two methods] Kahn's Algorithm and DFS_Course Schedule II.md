Construct adjacency list graph and inDegrees array. Then run Kahn"s algorithm.
# Kahn"s algorithm
- Create two arrays `noIncoming` and `doable` both empty initially
- Put all courses which have no prerequisites in `noIncoming`
- While `noIncoming` is not empty 
	- Pop a node from `noIncoming` and insert in `doable`
	- Traverse through adjacency list of this node and for each destination node in this adjacency list:
	  - Decrement `inDegree` of this destination node. This is equivalent to breaking an edge
	  - if `InDegree` is 0 then insert it into `noIncoming`

```
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>> G;
        unordered_map<int,int> inDegrees;
        vector<int> noIncoming, doable;
        
        for (auto p: prerequisites)
        {
            G[p[1]].push_back(p[0]);
            inDegrees[p[0]]++;
        }
        
        for (int i=0; i<numCourses; i++)
            if (inDegrees[i]==0)
                noIncoming.push_back(i);
        
        while (noIncoming.size()>0)
        {
            int curr = noIncoming.back();
            noIncoming.pop_back();
            doable.push_back(curr);
            for (int nbd: G[curr])
            {
                inDegrees[nbd]--;
                if (inDegrees[nbd]==0)
                    noIncoming.push_back(nbd);
            }
        }
        if (doable.size() < numCourses) return {};
        return doable;
    }
};
```

# DFS
Here we will need to maintain state of node during DFS. We do it using three colors: White(0) for not visited, Black(1) for visited and completed and Grey(2) for currently visiting and inside recursion.
```
// Colors: 0-Not visited, 1-visited and done, 2-visiting and recursion going on
class Solution {
    bool possible = true;

public:
    void dfs(unordered_map<int,vector<int>> &G, unordered_map<int,int> &colors, int curr, vector<int> &doable)
    {
        if (!this->possible) return;
        colors[curr] = 2;
        for (int nbd: G[curr])
        {
            if (colors[nbd]==0)
                dfs(G,colors,nbd,doable);
            else if (colors[nbd]==2)
                this->possible = false;
        }
        colors[curr] = 1;
        doable.push_back(curr);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>> G;
        unordered_map<int,int> colors;
        vector<int> doable;
        
        for (auto p: prerequisites)
            G[p[1]].push_back(p[0]);
        for (int i=0; i<numCourses; i++)
            colors[i] = 0;

        for (int curr=0; curr<numCourses; curr++)
        {
            if (colors[curr]==0)
                dfs(G, colors, curr, doable);
        }
        
        if (!this->possible) return {};
        reverse(doable.begin(), doable.end());
        return doable;
    }
};
```