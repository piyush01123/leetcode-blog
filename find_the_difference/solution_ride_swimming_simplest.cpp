class Solution {
public:
    char findTheDifference(string s, string t) {
        int xs=0, xt=0;
        for (char ch: s) xs^=(1<<(ch-'a'));
        for (char ch: t) xt^=(1<<(ch-'a'));
        int x = (xs^xt), p=0;
        while (x>0) {x/=2; p++;}
        return 'a'+p-1;
    }
};