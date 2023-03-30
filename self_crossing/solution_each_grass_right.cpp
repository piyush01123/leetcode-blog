class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        for (int i=0; i<distance.size(); i++)
        {
            if (i>=3) if (distance[i]>=distance[i-2] && distance[i-3]>=distance[i-1])
                return true;
            if (i>=4) if (distance[i]+distance[i-4]>=distance[i-2] && distance[i-1]==distance[i-3]) 
                return true;
            if (i>=5) if (distance[i]+distance[i-4]>=distance[i-2] && \
                          distance[i-1]+distance[i-5]>=distance[i-3] && \
                          distance[i-2]>=distance[i-4] && distance[i-3]>=distance[i-1]
                         )
                return true;
        }
        return false;
    }
};