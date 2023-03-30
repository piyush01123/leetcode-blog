class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int res=0;
        unordered_map<string,int> comps;
        for(string word: words)
        {
            if (comps.count(word) && comps[word])
            {
                res += 4;
                comps[word]--;
            }
            else
                comps[string(word.rbegin(),word.rend())]+=1;
        }
        for (auto p: comps)
        {
            string w=p.first; 
            int q=p.second;
            if (w[0]==w[1] && q>0)
            {
                res += 2;
                break;
            }
        }
        return res;
    }
};