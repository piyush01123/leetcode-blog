class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0) return true;
        unordered_map<int,vector<int>> graph;
        vector<int>targets;
        int n = arr.size();
        for (int i=0; i<n; i++) graph[i] = vector<int>{};
        for (int i=0; i<n; i++)
        {
            if(arr[i]==0) targets.push_back(i);
            else
            {
                if(i-arr[i]>=0 && i-arr[i]<n) graph[i].push_back(i-arr[i]);
                if(i+arr[i]>=0 && i+arr[i]<n) graph[i].push_back(i+arr[i]);
            }
        }
        vector<bool> visited = vector<bool>(n,false);
        list<int>queue;
        queue.push_back(start);
        while(!queue.empty())
        {
            int s = queue.front();
            queue.pop_front();
            for (int nbd: graph[s])
            {
                if(!visited[nbd])
                {
                    if (find(targets.begin(),targets.end(),nbd)!=targets.end()) return true;
                    visited[nbd] = true;
                    queue.push_back(nbd);
                }
            }
        }
        return false;
    }
};