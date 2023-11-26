class Solution {
public:
    int bin_to_int(string s)
    {
        int n=0;
        for (int i=0; i<s.length(); i++) if(s[s.length()-1-i]=='1') n+=(1<<i);
        return n;
    }
    string int_to_bin(int n, int len)
    {
        string s;
        while(n)
        {
            if(n%2) s.push_back('1');
            else s.push_back('0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        if(s.length()<len) s = string(len-s.length(),'0') + s;
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        unordered_set<int> numbers;
        for(string num: nums) numbers.insert(bin_to_int(num));
        for (int i=0; i<(1<<nums.size()); i++) if(!numbers.count(i)) return int_to_bin(i,numbers.size()); 
        return "";      
    }
};