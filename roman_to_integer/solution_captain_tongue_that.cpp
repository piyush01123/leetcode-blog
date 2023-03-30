class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> values;
        values['I']=1;
        values['V']=5;
        values['X']=10;
        values['L']=50;
        values['C']=100;
        values['D']=500;
        values['M']=1000;
        int res=values[s.back()];
        for (int i=0; i<s.size()-1; i++)
        {
            int curr=values[s[i]], next=values[s[i+1]];
            if (curr>=next) res+=curr;
            else res-=curr;
        }
        return res;
    }
};