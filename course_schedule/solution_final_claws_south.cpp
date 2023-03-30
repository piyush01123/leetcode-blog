class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>>  G;
        unordered_map<int,int> inDegrees;
        vector<int> noIncoming, doable;
        
        for (auto p: prerequisites)
        {
            G[p[1]].push_back(p[0]);
            inDegrees[p[0]] ++;
        }
        
        for (int i=0; i<numCourses; i++)
            if (inDegrees[i]==0)
                noIncoming.push_back(i);
        
        while (noIncoming.size()>0)
        {
            int curr = noIncoming.back();
            // cout << curr << endl;
            noIncoming.pop_back();
            doable.push_back(curr);
            for (int nbd: G[curr])
            {
                inDegrees[nbd]--;
                if (inDegrees[nbd]==0)
                    noIncoming.push_back(nbd);
            }
        }
        
        return doable.size()==numCourses;
    }
};