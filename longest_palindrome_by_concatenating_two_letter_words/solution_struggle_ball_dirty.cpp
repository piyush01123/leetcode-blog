class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int res=0;
        unordered_map<string,int> H;
        for(string word: words) H[word]+=1;
        bool central = false;
        for (auto pair: H)
        {
            string w=pair.first;
            if (w[0]==w[1])
            {
                if (H[w]%2==0)
                    res += 2*H[w];
                else
                {
                    res += 2*(H[w]-1);
                    central = true;
                }
                continue;
            }
            if (w[0]>w[1]) continue;
            string rev(w.rbegin(), w.rend());
            if (!H.count(rev)) continue;
            res += 4*min(H[w], H[rev]);
        }
        if (central) res+=2;
        return res;
    }
};