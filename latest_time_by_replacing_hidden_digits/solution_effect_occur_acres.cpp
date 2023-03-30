class Solution {
public:
    string maximumTime(string time) {
        string hh = time.substr(0,2), mm = time.substr(3,5);
        char h1 = hh.at(0), h2 = hh.at(1);
        char m1 = mm.at(0), m2 = mm.at(1);
        // cout<<"H1:"<<h1<<" H2:"<<h2<<" M1:"<<m1<<" M2:"<<m2<<'\n';
        m2 = (m2=='?')?'9':m2;
        m1 = (m1=='?')?'5':m1;
        h1 = (h1=='?')?((h2>='0'&&h2<='3')?'2':'1'):h1;
        h2 = (h2=='?')?((h1=='2')?'3':'9'):h2;
        if (hh=="??") {h1='2';h2='3';}
        if (mm=="??") {m1='5';m2='9';}
        string s = ""; s.insert(0,1,m2); s.insert(0,1,m1); s.insert(0,1,':'); s.insert(0,1,h2); s.insert(0,1,h1);
        return s;        
    }
};

