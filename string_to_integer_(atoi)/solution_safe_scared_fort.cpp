class Solution {
public:
    int myAtoi(string s) {
        // cout << "***" << s << "***" << endl;
        int curr=0, sign=+1, i=0;
        while (i<s.size()&&s[i]==' ')i++;
        if (i==s.size()) return 0;
        if (s[i]=='-') sign=-1;
        if (s[i]=='-'||s[i]=='+'){i++;}
        if (i==s.size()) return 0;
        // cout << "#***" << s << "***#" << sign << endl;
        while (i<s.size()&&'0'<=s[i]&&s[i]<='9')
        {
            int num = s[i]-'0';
            if (curr>INT_MAX/10 || 10*curr>INT_MAX-num) return (sign==1)?INT_MAX:INT_MIN;
            curr = 10*curr+num;
            i++;
            // cout << curr << endl;
        }
        return sign*curr;
    }
};