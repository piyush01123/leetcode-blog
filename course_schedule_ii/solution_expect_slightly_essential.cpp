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