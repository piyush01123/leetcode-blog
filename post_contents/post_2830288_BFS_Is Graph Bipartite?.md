The idea is to check if a two-color coloring can be done to the graph. Colors={1,-1} and 0 denotes uncolored. Start with node 0 and traverse by BFS. Then for any other connected component repeat. To do this, we can run for all i from 0 to n and only start doing BFS if it is uncolored.

Note that uncolored = unvisited.


```
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        vector<int> colors = vector<int>(V,0);
        queue<int> Q;

        for (int i=0; i<V; i++)
        {
            if (colors[i]!=0) continue;
            colors[i] = 1;
            Q.push(i);
            while(!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                for (int v: graph[u])
                {
                    if (colors[v]==0)
                    {
                        colors[v] = -colors[u];
                        Q.push(v);
                    }
                    else
                        if (colors[v]==colors[u])
                            return false;
                }
            }
        }
        return true;
    }
};
```