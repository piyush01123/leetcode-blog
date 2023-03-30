class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> H;
        int n = arr.size();
        for (int i=0; i<n; i++)
        {
            if (H.find(arr[i])==H.end()) H[arr[i]] = vector<int>{i};
            else H[arr[i]].push_back(i);
        }
        vector<long long> res(n,0);
        for (auto item: H)
        {
            vector<int> indices = item.second;
            int m = indices.size();
            long long S = 0;
            for (int i=1; i<m; i++) S=S+(long long)indices[i]-(long long)indices[0];
            res[indices[0]] = S;
            for (int i=1; i<m; i++)
            {
                long long d = indices[i]-indices[i-1];
                S = S-d*(long long)(m-1-i+1)+d*(long long)i;
                res[indices[i]] = S;

            }
        }
        return res;
    }
};