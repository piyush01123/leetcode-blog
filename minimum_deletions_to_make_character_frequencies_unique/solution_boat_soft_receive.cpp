class Solution {
public:
    int minDeletions(string s) 
    {
       unordered_map<char,int>H;
       for (char ch: s) H[ch]++;
       unordered_set<int> used;
       int ctr = 0;
       for (auto &p: H)
       {
           int freq = p.second;
           while (freq>0 && used.count(freq))
           {
               freq--;
               ctr++;
           }
           used.insert(freq);
       }
       return ctr; 
    }
};