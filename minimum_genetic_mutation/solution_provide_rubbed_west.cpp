class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        unordered_set<string>covered;
        covered.insert(start);
        int ctr = 0;
        queue<string> Q;
        Q.push(start);
        while (!Q.empty())
        {
            for (int i=Q.size()-1; i>=0; i--)
            {
                string u = Q.front();
                Q.pop();
                if (u==end) return ctr;
                for (char ch: "ACGT")
                {
                    for (int i=0; i<8; i++)
                    {
                        string nbd = u;
                        nbd[i]=ch;
                        if (!covered.count(nbd) && find(bank.begin(),bank.end(),nbd)!=bank.end())
                        {
                            covered.insert(nbd);
                            Q.push(nbd);
                        }
                    }
                }
            }
            ctr++;
        }
        return -1;
    }
};