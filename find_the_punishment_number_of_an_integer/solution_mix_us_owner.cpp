class Solution {
public:
    bool util(int candidate, int target) //candidate=i*i, target=i, ex: (1296,36)
    {
        if (target<0) return false;
        if (candidate==0) return false;
        bool a =  (candidate==target);
        bool b = util(candidate/10, target-candidate%10);
        bool c = util(candidate/100, target-candidate%100);
        bool d = util(candidate/1000, target-candidate%1000);
        return (a|b|c|d);
    }
    int punishmentNumber(int n) 
    {
        int res=0;
        for(int i=1; i<=n; i++) if(util(i*i, i)) res+= i*i;
        return res;
    }
};