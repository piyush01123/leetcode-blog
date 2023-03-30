class Solution {
public:
    pair<char,int> getLFC(string s)
    {
        unordered_map<char,int> H;
        for (char ch: s)
            H[ch]++;
        char minCh; int minFreq=INT_MAX;
        for (auto p: H)
        {
            char ch = p.first;
            int freq = p.second;
            if (freq<minFreq)
            {
                minCh = ch;
                minFreq = freq;
            }
        }
        return {minCh, minFreq};
    }    

    vector<string> split(string str, char del)
    {
        vector<string> vec;
        string temp = "";
        for(int i=0; i<(int)str.size(); i++)
        {
            if(str[i] != del) temp += str[i];
            else
            {
                vec.push_back(temp);
                temp = "";
            }
        }
        vec.push_back(temp);
        return vec;
    }    

    int longestSubstring(string s, int k) 
    {
        if (k > s.length()) return 0;
        auto lfcp = getLFC(s);
        char lfc = lfcp.first;
        int lfcFreq = lfcp.second;
        if (lfcFreq >= k) return s.length();
        vector<string> splits = split(s, lfc);
        int currMax = 0;
        for (string split: splits)
        {
            int curr = longestSubstring(split, k);
            if (curr > currMax)
                currMax = curr;
        }
        return currMax;
    }
};