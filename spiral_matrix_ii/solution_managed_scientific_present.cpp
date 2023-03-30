class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> M(n, vector<int>(n,0));
        vector<int>v;
        for (int i=1;i<n;i++){v.push_back(i);v.push_back(i);} v.push_back(n-1);
        reverse(v.begin(),v.end());
        // 3,2,2,1,1
        int curr=1;
        int x=0,y=0;
        for (int i=0; i<v.size(); i++)
        {
            for (int j=0; j<v[i]; j++)
            {
                M[x][y]=curr;
                curr++;
                if (i%4==0) y++;
                if (i%4==1) x++;
                if (i%4==2) y--;
                if (i%4==3) x--;
            }
        }
        M[x][y]=curr;
        return M;
    }
};