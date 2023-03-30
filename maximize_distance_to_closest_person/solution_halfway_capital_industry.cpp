class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size(), prev,i=0;
        vector<int>leftDist(n,0),rightDist(n,0),dist(n,0);
        while(i<n && seats[i]==0){leftDist[i]=INT_MAX;i++;}
        while(i<n)
        {
            if(seats[i]) prev=i;
            else leftDist[i]=i-prev;
            i++;
        }
        i=n-1;
        while(i>=0 && seats[i]==0){rightDist[i]=INT_MAX;i--;}
        while(i>=0)
        {
            if(seats[i]) prev=i;
            else rightDist[i]=prev-i;
            i--;
        }
        int res=INT_MAX;
        for(i=0;i<n;i++)
            dist[i] = min(leftDist[i],rightDist[i]);
        return *max_element(dist.begin(),dist.end());
    }
};