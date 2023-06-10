class Solution {
public:
    bool util(string str, int target) //str=i*i, target=i, ex: ("1296",36)
    {
        if (target<0) return false;
        if (target==0 && str=="") return true;
        bool cur = false;
        for (int i=0; i<str.length(); i++)
        {
            int left = stoi(str.substr(0,i+1));
            int right = (i==str.length()-1)?0:stoi(str.substr(i+1));
            if (left+right==target) return true;
            cur |= util(str.substr(i+1), target-left);
            if (cur) return true;
        }
        return cur;
    }
    int punishmentNumber(int n) 
    {
        int res=0;
        for (int i=1; i<=n; i++)
            if (util(to_string(i*i), i)) res+= i*i;
        return res;
    }
};