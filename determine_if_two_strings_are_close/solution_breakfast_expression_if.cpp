class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        int n=word1.length();
        if (word2.length()!=n) return false;

        unordered_map<char,int> H1, H2;
        unordered_map<int,int> HH1, HH2;
        for (int i=0; i<n; i++)
        {
            char ch1=word1[i], ch2=word2[i];
            if (!H1.count(ch1)) H1[ch1] = 0;
            if (!H2.count(ch2)) H2[ch2] = 0;
            H1[ch1]++; H2[ch2]++;
        }
        for (auto &p: H1)
        {
            char ch = p.first;
            int freq = p.second;
            if (!H2.count(ch)) return false;
            if (!HH1.count(freq)) HH1[freq]=0;
            HH1[freq]++;
        }
        for (auto &p: H2)
        {
            char ch = p.first;
            int freq = p.second;
            if (!H1.count(ch)) return false;
            if (!HH2.count(freq)) HH2[freq]=0;
            HH2[freq]++;
        }
        for (auto &p: HH1)
        {
            if (!HH2.count(p.first) || p.second!=HH2[p.first])
                return false;
        }
        for (auto &p: HH2)
        {
            if (!HH1.count(p.first) || p.second!=HH1[p.first])
                return false;
        }
        return true;
    }
};