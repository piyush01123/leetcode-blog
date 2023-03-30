class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> M(n, vector<int>(n,0));
        int x=0, y=0, curr=1, x_min=0, x_max=n-1, y_min=0, y_max=n-1;
        while (x>x_min||x<x_max||y>y_min||y<y_max)
        {
            while (y<y_max) M[x][y++]=curr++; x_min++;
            while (x<x_max) M[x++][y]=curr++; y_max--;
            while (y>y_min) M[x][y--]=curr++; x_max--;
            while (x>x_min) M[x--][y]=curr++; y_min++;     
        }
        M[x][y]=curr;
        return M;
    }
};