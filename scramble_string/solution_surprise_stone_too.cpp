class Solution {
    unordered_map<string,bool> H;
public:
    bool isScramble(string s1, string s2) 
    {
        if (H.count(s1+","+s2)) return H[s1+","+s2];
        if(s1==s2) return H[s1+","+s2] = true;
        int len = s1.length();
        vector<int> count(26,0);
        for(int i=0; i<len; i++) {count[s1[i]-'a']++; count[s2[i]-'a']--;}
        for(int i=0; i<26; i++) if(count[i]!=0) return H[s1+","+s2] = false; 
        for(int i=1; i<len; i++)
        {
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && \
                isScramble(s1.substr(i), s2.substr(i))) return H[s1+","+s2] = true;
            if(isScramble(s1.substr(0,i), s2.substr(len-i)) && \
                isScramble(s1.substr(i), s2.substr(0,len-i))) return H[s1+","+s2] = true;
        }
        return H[s1+","+s2] = false;
    }
};