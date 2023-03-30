class Solution {
public:
    vector<string> getNeighbors(string gene)
    {
        // Returns vector of size 4^8
        vector<string> neighbors;
        for (int i=0; i<8; i++)
        {
            for (char ch: "ACGT")
            {
                string neighbor = gene;
                neighbor[i]=ch;
                neighbors.push_back(neighbor);
            }
        }
        return neighbors;
    }
    
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string> covered, bankSet;
        for (string gene: bank) bankSet.insert(gene);
        queue<string> Q;
        covered.insert(startGene);
        Q.push(startGene);
        int ctr = 0;
        while (!Q.empty())
        {
            for (int i=Q.size(); i>0; i--)
            {
                string u = Q.front();
                Q.pop();
                if (u==endGene) return ctr;
                for (string nbd: getNeighbors(u))
                {
                    if (!covered.count(nbd) && bankSet.count(nbd))
                    {
                        Q.push(nbd);
                        covered.insert(nbd);
                    }
                }
            }
            ctr++;
        }
        return -1;
    }
};