class Solution {
     int helper(int src,vector<vector<int>>& g,vector<int>& size){
         int ans = 1;
         for(auto child:g[src]){
             ans += helper(child,g,size);
         }
         return size[src] = ans; 
     }
    
    
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> size(n,0);  // size[i] indicates size of subtree(rooted at i node) + 1
        vector<vector<int>> g(n); // storing left and right child of a node
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }
        helper(0,g,size);  // calculating size of each subtree
        long long cnt = 0, maxi = 0;
        for(int i=0;i<n;i++){
            long long pro = 1; 
            pro = max(pro,(long long)n - size[i]); // calculating leftover nodes excluding child nodes 
            for(auto node:g[i]){
                pro = pro * size[node]; // multiplying with size of subtree
            }
            if(pro > maxi){
                maxi = pro;
                cnt = 1;
            }
            else if(pro == maxi){
                cnt++;
            }
        }
        return cnt;
    }
};