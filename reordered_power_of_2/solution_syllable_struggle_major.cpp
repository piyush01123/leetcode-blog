class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        int ndigits=0, ncopy = n;
        unordered_map<int,int> H{{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}};
        while (ncopy)
        {
            H[ncopy%10] ++;
            ncopy/=10;
            ndigits ++;
        }
        
        vector<unordered_map<int,int>> HTargetall;
        int p = 1;
        while(1)
        {
            int pdigits=0, pcopy=p;
            unordered_map<int,int> HTarget{{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}};
            int pdgits = 0;
            while(pcopy)
            {
                HTarget[pcopy%10] ++;
                pcopy /= 10;
                pdigits ++;
            }
            if (pdigits==ndigits) HTargetall.push_back(HTarget);
            if (pdigits >ndigits || p>1000000007) break;
            p <<= 1;
        }
        
        for (auto HTarget: HTargetall)
        {
            bool ok=true;
            for (int i=0; i<=9; i++)
            {
                if (HTarget[i]!=H[i])
                {
                    ok=false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
        
    }
};