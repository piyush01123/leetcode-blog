bool my_comp(vector<int>&v1, vector<int>&v2)
{
    if (v1[0]==v2[0]) return v1[1]>v2[1];
    return v1[0]<v2[0];
}
bool comp_second(const pair<int,int>&p1, const pair<int,int>&p2)
{
    return p1.second<p2.second;
}
void pv(vector<pair<int,int>> &subseq)
{
    for(auto &p: subseq)cout<<'('<<p.first<<','<<p.second<<')'<<',';cout<<endl;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),my_comp);
        vector<pair<int,int>> subseq;
        for (auto &env: envelopes)
        {
            // cout << env[0]<<' '<<env[1]<<endl;
            if (subseq.size()==0)
                subseq.push_back({env[0],env[1]});
            else if (env[0]>subseq.back().first && env[1]>subseq.back().second)
                subseq.push_back({env[0],env[1]});
            else
            {
                vector<pair<int,int>>::iterator it;
                pair<int,int>p = pair<int,int>{env[0],env[1]};
                it = lower_bound(subseq.begin(),subseq.end(),p,comp_second);
                if (it==subseq.end()) continue;
                // cout << it-subseq.begin()<<endl;
                *it = p;
            }
            // pv(subseq);
        }
        return subseq.size();
    }
};