class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> rom2int;
        rom2int['I']=1;
        rom2int['V']=5;
        rom2int['X']=10;
        rom2int['L']=50;
        rom2int['C']=100;
        rom2int['D']=500;
        rom2int['M']=1000;
        int ans = 0;
        for (int i=0; i<s.size()-1; i++)
        {
            int curr=rom2int[s[i]], next=rom2int[s[i+1]];
            if (curr>=next) ans+=curr;
            else ans-=curr;
        }
        ans += rom2int[s[s.size()-1]];
        return ans;        
    }
};