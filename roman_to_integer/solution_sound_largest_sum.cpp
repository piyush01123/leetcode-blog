class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> values {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
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