class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        // O(N)
        int n = fruits.size(), res=0, i=0;
        if(n==1) return 1;
        unordered_map<int,int> H;
        for (int j=0; j<n; j++)
        {
            H[fruits[j]]++;
            while(i<n && H.size()>2)
            {
                H[fruits[i]]--;
                if (H[fruits[i]]==0) H.erase(fruits[i]);
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};