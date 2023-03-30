class Solution {
public:
    void dfs(vector<vector<int>> &image, int i, int j, int m, int n, int color, int t)
    {
        if (i<0||i>=m||j<0||j>=n||image[i][j]!=t||image[i][j]==color) return;
        image[i][j] = color;
        dfs(image,i-1,j,m,n,color,t);
        dfs(image,i+1,j,m,n,color,t);
        dfs(image,i,j-1,m,n,color,t);
        dfs(image,i,j+1,m,n,color,t);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
       int m=image.size(), n=image[0].size();
        dfs(image, sr, sc, m, n, color, image[sr][sc]);
        return image;
    }
};