class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<vector<pair<int,int>>>G(n);
        for (auto &edge: redEdges) G[edge[0]].push_back({edge[1],0});
        for (auto &edge: blueEdges) G[edge[0]].push_back({edge[1],1});
        // for(int i=0;i<n;i++){cout<<i<<':';for(auto item:G[i])cout<<item.first<<'.'<<item.second<<',';cout<<endl;}
        vector<int> res(n,-1);
        res[0] = 0;
        queue<vector<int>> Q;
        Q.push({0,-1});
        vector<vector<bool>> visited(n, vector<bool>{false,false});
        visited[0] = {true,true};
        int distance = 0;
        while (!Q.empty())
        {
            distance++;
            for(int i=Q.size(); i>0; i--)
            {
                auto cur = Q.front();
                Q.pop();
                int curNode=cur[0], curColor=cur[1];
                for (auto &nbd: G[curNode])
                {
                    int nbdNode=nbd.first, nbdColor=nbd.second;
                    if (!visited[nbdNode][nbdColor] && nbdColor!=curColor)
                    {
                        visited[nbdNode][nbdColor] = true;
                        if(res[nbdNode]==-1)res[nbdNode] = distance;
                        Q.push({nbdNode,nbdColor});
                    }
                }
            }
        }
        return res;
    }
};