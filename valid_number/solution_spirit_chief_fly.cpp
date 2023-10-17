class Solution {
public:
    bool isNumber(string s, bool flag=true) 
    {   
        // Uncomment to run all tests
        // if(flag)
        // {
        //     vector<string> tests{"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};
        //     for(string test: tests) cout<<test<<' '<< (isNumber(test, false)?"TRUE":"FALSE" )<< endl;     
        // }
        unordered_map<char, unordered_map<string,char>> stateMap;
        stateMap['A'] = {{"dig",'B'}, {"dot",'C'}, {"sig",'D'}};
        stateMap['B'] = {{"dig",'B'}, {"dot",'E'}, {"exp",'F'}};
        stateMap['C'] = {{"dig",'E'}};
        stateMap['D'] = {{"dot",'C'}, {"dig",'B'}};
        stateMap['E'] = {{"dig",'E'}, {"exp",'F'}};
        stateMap['F'] = {{"dig",'G'}, {"sig",'H'}};
        stateMap['G'] = {{"dig",'G'}};
        stateMap['H'] = {{"dig",'G'}};
        char cur = 'A';
        for (char ch: s)
        {
            string state;
            if (ch>='0' && ch<='9') state="dig";
            else if (ch=='+' || ch=='-') state="sig";
            else if (ch=='e' || ch=='E') state ="exp";
            else if (ch=='.') state="dot";
            else return false;
            if (!stateMap[cur].count(state)) return false;
            cur = stateMap[cur][state];
        }
        return (cur=='B' || cur=='E' || cur=='G');
    }
};
