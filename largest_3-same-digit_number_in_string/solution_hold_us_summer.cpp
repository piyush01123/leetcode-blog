class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for (int i=0; i<num.length()-2; i++) if(num[i]==num[i+1] && num[i]==num[i+2])
        if(res.length()==0 || res[0]<num[i]) res = num.substr(i,3);
        return res; 
    }
};